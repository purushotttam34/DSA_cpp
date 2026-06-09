// 1 → Wall
// 0 → Open path
// S → Start position
// E → Exit position

#include<iostream>
#include<stack>
#include<vector>
#include<fstream>
#include<string>

using namespace std;


struct Position {
    int row;
    int col;
};

int main() {
    ifstream file("maze.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    vector<string> maze;
    string line;

    while (getline(file, line)) {
        maze.push_back(line);
    }

    file.close();

    int rows = maze.size();
    int cols = maze[0].size();

    Position start, end;

    // Find Start and End positions
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'S') {
                start.row = i;
                start.col = j;
            }
            if (maze[i][j] == 'E') {
                end.row = i;
                end.col = j;
            }
        }
    }

    stack<Position> st;
    st.push(start);

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    bool found = false;

    int dr[] = {-1, 0, 1, 0}; // Up, Right, Down, Left
    int dc[] = {0, 1, 0, -1};

    while (!st.empty()) {
        Position current = st.top();
        st.pop();

        int r = current.row;
        int c = current.col;

        if (visited[r][c])
            continue;

        visited[r][c] = true;

        if (maze[r][c] != 'S' && maze[r][c] != 'E')
            maze[r][c] = '.';

        if (r == end.row && c == end.col) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                !visited[nr][nc] &&
                (maze[nr][nc] == '0' || maze[nr][nc] == 'E')) {

                st.push({nr, nc});
            }
        }
    }

    if (found) {
        cout << "_____Maze Solved! Exit Found_____.\n\n"<<endl<<"'.' part represent the explored part"<<'endl';

        for (const string &row : maze) {
            cout << row << endl;
        }
    } else {
        cout << "No path found!" << endl;
    }

    return 0;
}