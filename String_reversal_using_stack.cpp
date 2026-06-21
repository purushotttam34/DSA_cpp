#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cout<<"Stack Reversal Using Stack"<<endl;
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    stack<char> st;

    // Push every character into stack
    for(char ch : str)
    {
        st.push(ch);
    }

    string reversed = "";

    // Pop characters one by one
    while(!st.empty())
    {
        reversed += st.top();
        st.pop();
    }

    cout << "Reversed String = "
         << reversed;

    return 0;
}