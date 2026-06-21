#include <iostream>
#include <stack>
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

// Function to convert infix expression to postfix
string infixToPostfix(string exp)
{
    stack<char> st;
    string result = "";

    for(char ch : exp)
    {
        // If operand, add directly to output
        if(isalnum(ch))
        {
            result += ch;
        }

        // If opening bracket, push to stack
        else if(ch == '(')
        {
            st.push(ch);
        }

        // If closing bracket
        else if(ch == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }

            st.pop(); // Remove '('
        }

        // Operator encountered
        else
        {
            while(!st.empty() &&
                  precedence(st.top()) >= precedence(ch))
            {
                result += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    // Pop remaining operators
    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"Infix to Postfix Conversion"<<endl;
    string exp;

    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix Expression = "
         << infixToPostfix(exp);

    return 0;
}