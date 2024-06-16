#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operand
bool isOperand(char x)
{
    return !(x == '+' || x == '-' || x == '*' || x == '/');
}

// Function to determine the precedence of an operator
int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

// Function to convert an infix expression to postfix expression
string infixToPostfix(const string &infix)
{
    stack<char> st; // Stack to hold operators
    string postfix; // Resultant postfix expression
    st.push('#');   // Add a sentinel to the stack

    // Iterate through each character in the infix expression
    for (int i = 0; i < infix.length(); i++)
    {
        // If the character is an operand, add it to the postfix expression
        if (isOperand(infix[i]))
        {
            postfix += infix[i];
        }
        else
        {
            // If the character is an operator, pop from stack to postfix until the stack is empty or has an operator of lower precedence
            while (!st.empty() && precedence(infix[i]) <= precedence(st.top()))
            {
                postfix += st.top(); // Add the operator to the postfix expression
                st.pop();            // Remove the operator from the stack
            }
            st.push(infix[i]); // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators from the stack and add to postfix
    while (!st.empty() && st.top() != '#')
    {
        postfix += st.top();
        st.pop();
    }

    return postfix; // Return the resultant postfix expression
}

int main()
{
    string infix = "a+b*c-d/e";             // Sample infix expression
    string postfix = infixToPostfix(infix); // Convert infix to postfix
    cout << postfix << endl;                // Output the postfix expression
    return 0;
}
