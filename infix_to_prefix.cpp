#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to determine operator precedence
int precedence(char op)
{
    if(op == '^')
        return 3;
    if(op == '*' || op == '/')
        return 2;
    if(op == '+' || op == '-')
        return 1;

    return 0;
}

// Function to convert infix to prefix
string infixToPrefix(string infix)
{
    // Reverse infix expression
    reverse(infix.begin(), infix.end());

    // Swap brackets
    for(char &ch : infix)
    {
        if(ch == '(')
            ch = ')';
        else if(ch == ')')
            ch = '(';
    }

    stack<char> st;
    string postfix = "";

    // Convert reversed expression to postfix
    for(char ch : infix)
    {
        if(isalnum(ch))
        {
            postfix += ch;
        }
        else if(ch == '(')
        {
            st.push(ch);
        }
        else if(ch == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }

            st.pop();
        }
        else
        {
            while(!st.empty() &&
                  precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    // Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main()
{
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"Infix to Prefix Conversion"<<endl;
    string exp;

    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Prefix Expression = "
         << infixToPrefix(exp);

    return 0;
}