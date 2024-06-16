#include <iostream>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

// Function to check if the given expression has balanced parentheses
int isBalanced(char *exp)
{
    // Create a map to store the matching pairs of parentheses
    map<char, char> mapping;
    mapping['}'] = '{';
    mapping[')'] = '(';
    mapping[']'] = '[';

    // Create an iterator for the map
    map<char, char>::iterator itr;

    // Create a stack to keep track of opening parentheses
    stack<char> stk;

    // Iterate through each character in the expression
    for (int i = 0; i < strlen(exp); i++)
    {
        // If the character is an opening parenthesis, push it onto the stack
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            stk.push(exp[i]);
        }
        // If the character is a closing parenthesis
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            // If the stack is empty, it means there's no matching opening parenthesis
            if (stk.empty())
            {
                return false;
            }
            else
            {
                // Get the top element of the stack
                char temp = stk.top();
                // Find the corresponding opening parenthesis for the current closing parenthesis
                itr = mapping.find(exp[i]);
                // Check if the top element of the stack matches the corresponding opening parenthesis
                if (temp == itr->second) // itr->first is key, itr->second is value
                {
                    // If it matches, pop the top element from the stack
                    stk.pop();
                }
                else
                {
                    // If it doesn't match, the expression is not balanced
                    return false;
                }
            }
        }
    }
    // If the stack is empty after processing all characters, the expression is balanced
    return stk.empty() ? true : false;
}

int main()
{
    // Test the isBalanced function with different expressions

    char A[] = "{([a+b]*[c-d])/e}";
    cout << isBalanced(A) << endl; // Expected output: 1 (true)

    char B[] = "{([a+b]}*[c-d])/e}";
    cout << isBalanced(B) << endl; // Expected output: 0 (false)

    char C[] = "{([{a+b]*[c-d])/e}";
    cout << isBalanced(C) << endl; // Expected output: 0 (false)

    return 0;
}
