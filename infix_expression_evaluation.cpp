#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence
int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;

    if(op == '*' || op == '/')
        return 2;

    return 0;
}

// Function to apply operation
int applyOperation(int a, int b, char op)
{
    switch(op)
    {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;
    }

    return 0;
}

int main()
{
    string exp;

    cout << "Enter infix expression: ";
    cin >> exp;

    stack<int> values;
    stack<char> operators;

    for(int i = 0; i < exp.length(); i++)
    {
        // Operand
        if(isdigit(exp[i]))
        {
            values.push(exp[i] - '0');
        }
        else
        {
            while(!operators.empty() &&
                  precedence(operators.top()) >= precedence(exp[i]))
            {
                int b = values.top();
                values.pop();

                int a = values.top();
                values.pop();

                char op = operators.top();
                operators.pop();

                values.push(applyOperation(a, b, op));
            }

            operators.push(exp[i]);
        }
    }

    // Evaluate remaining operators
    while(!operators.empty())
    {
        int b = values.top();
        values.pop();

        int a = values.top();
        values.pop();

        char op = operators.top();
        operators.pop();

        values.push(applyOperation(a, b, op));
    }

    cout << "Result = " << values.top();

    return 0;
}