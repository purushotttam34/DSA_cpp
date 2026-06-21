#include <iostream>
#include <stack>
using namespace std;

// Function to check balanced parentheses
bool isBalanced(string exp)
{
    stack<char> st;

    for(char ch : exp)
    {
        // Push opening brackets
        if(ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }

        // Check closing brackets
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(st.empty())
                return false;

            char top = st.top();
            st.pop();

            if((ch == ')' && top != '(') ||
               (ch == '}' && top != '{') ||
               (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }

    // Stack must be empty
    return st.empty();
}

int main()
{
    cout<<"Paranthesis Matching"<<endl;
    string exp;

    cout << "Enter expression: ";
    cin >> exp;

    if(isBalanced(exp))
        cout << "Balanced Parentheses";
    else
        cout << "Not Balanced";

    return 0;
}