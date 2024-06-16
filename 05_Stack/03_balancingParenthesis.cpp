#include <iostream>
#include <string.h>
using namespace std;

// Stack class definition
class Stack
{
private:
    int size; // Size of the stack
    int top;  // Index of the top element in the stack
    char *S;  // Pointer to the stack array

public:
    Stack(int size);             // Constructor to initialize the stack
    ~Stack();                    // Destructor to deallocate the stack memory
    void push(char x);           // Method to push an element onto the stack
    char pop();                  // Method to pop an element from the stack
    char peek(int index);        // Method to peek at an element at a specific position
    int isFull();                // Method to check if the stack is full
    int isEmpty();               // Method to check if the stack is empty
    void display();              // Method to display the stack elements
    char stackTop();             // Method to get the top element of the stack
    bool isBalanced(string exp); // Method to check if an expression is balanced
};

// Constructor to initialize the stack
Stack::Stack(int size)
{
    this->size = size;  // Set the size of the stack
    top = -1;           // Initialize top to -1 indicating an empty stack
    S = new char[size]; // Allocate memory for the stack array
}

// Destructor to deallocate the stack memory
Stack::~Stack()
{
    delete[] S; // Deallocate the memory
}

// Method to push an element onto the stack
void Stack::push(char x)
{
    if (isFull()) // Check if the stack is full
    {
        cout << "Stack Overflow!" << endl; // Print overflow message
    }
    else
    {
        top++;      // Increment the top index
        S[top] = x; // Add the element to the stack
    }
}

// Method to pop an element from the stack
char Stack::pop()
{
    char x = 1;
    if (isEmpty()) // Check if the stack is empty
    {
        cout << "Stack Underflow!" << endl; // Print underflow message
    }
    else
    {
        x = S[top]; // Get the top element
        top--;      // Decrement the top index
    }
    return x; // Return the popped element
}

// Method to peek at an element at a specific position
char Stack::peek(int index)
{
    char x = -1;
    if (top - index + 1 < 0 || top - index + 1 == size) // Check if the index is valid
    {
        cout << "Invalid position!" << endl; // Print invalid position message
    }
    else
    {
        x = S[top - index + 1]; // Get the element at the specified position
    }
    return x; // Return the element
}

// Method to check if the stack is full
int Stack::isFull()
{
    return top == size - 1; // Return true if the stack is full
}

// Method to check if the stack is empty
int Stack::isEmpty()
{
    return top == -1; // Return true if the stack is empty
}

// Method to display the stack elements
void Stack::display()
{
    for (int i = top; i >= 0; i--) // Iterate from top to bottom
    {
        cout << S[i] << " | " << flush; // Print each element
    }
    cout << endl;
}

// Method to get the top element of the stack
char Stack::stackTop()
{
    if (isEmpty()) // Check if the stack is empty
    {
        return -1; // Return -1 if the stack is empty
    }
    return S[top]; // Return the top element
}

// Method to check if an expression is balanced
bool Stack::isBalanced(string exp)
{
    for (int i = 0; exp[i] != '\0'; i++) // Iterate through each character in the expression
    {
        if (exp[i] == '(') // If the character is '(', push it onto the stack
        {
            push(exp[i]);
        }
        else if (exp[i] == ')') // If the character is ')', pop an element from the stack
        {
            if (isEmpty()) // If the stack is empty, return false
                return false;
            pop();
        }
    }
    return isEmpty(); // Return true if the stack is empty, false otherwise
}

int main()
{
    string alpha = "((a+b)*(a+b))";                          // Input expression
    Stack stk(alpha.length());                               // Create a stack with size equal to the length of the expression
    cout << "Is string balanced? " << stk.isBalanced(alpha); // Check if the expression is balanced and print the result
    return 0;
}
