#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    stack<int> st;

    for(char ch : postfix)
    {
        // If operand, push into stack
        if(isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            // Pop two operands
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            // Perform operation
            switch(ch)
            {
                case '+':
                    st.push(a + b);
                    break;

                case '-':
                    st.push(a - b);
                    break;

                case '*':
                    st.push(a * b);
                    break;

                case '/':
                    st.push(a / b);
                    break;
            }
        }
    }

    cout << "Result = " << st.top();

    return 0;
}