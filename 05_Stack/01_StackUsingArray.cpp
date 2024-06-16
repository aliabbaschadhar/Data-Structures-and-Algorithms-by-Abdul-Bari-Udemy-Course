#include <iostream>
#include <stack>
using namespace std;

// Template class for Stack
template <class T>
class Stack
{
private:
    int size; // Maximum size of the stack
    int top;  // Index of the top element
    T *S;     // Pointer to the array representing the stack

public:
    Stack(int size);   // Constructor to initialize the stack
    ~Stack();          // Destructor to clean up memory
    void push(T x);    // Add an element to the stack
    T pop();           // Remove an element from the stack
    T peek(int index); // Get the element at a specific index
    int isFull();      // Check if the stack is full
    int isEmpty();     // Check if the stack is empty
    void display();    // Display the elements in the stack
    T stackTop();      // Get the top element of the stack
};

// Constructor to initialize the stack
template <class T>
Stack<T>::Stack(int size)
{
    this->size = size;
    top = -1;
    S = new T[size]; // Allocate memory for the stack
}

// Destructor to free the allocated memory
template <class T>
Stack<T>::~Stack()
{
    delete[] S;
}

// Function to add an element to the stack
template <class T>
void Stack<T>::push(T x)
{
    if (isFull())
    {
        cout << "Stack Overflow!" << endl; // Check if stack is full
    }
    else
    {
        top++;
        S[top] = x; // Add element to the top of the stack
    }
}

// Function to remove an element from the stack
template <class T>
T Stack<T>::pop()
{
    T x = -1;
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl; // Check if stack is empty
    }
    else
    {
        x = S[top]; // Retrieve the top element
        top--;      // Move the top pointer down
    }
    return x;
}

// Function to get the element at a specific index
template <class T>
T Stack<T>::peek(int index)
{
    T x = -1;
    if (top - index + 1 < 0 || top - index + 1 == size)
    {
        cout << "Invalid position!" << endl; // Check if index is valid
    }
    else
    {
        x = S[top - index + 1]; // Retrieve the element at the specified index
    }
    return x;
}

// Function to check if the stack is full
template <class T>
int Stack<T>::isFull()
{
    return (top == size - 1); // Return true if top is at the last index
}

// Function to check if the stack is empty
template <class T>
int Stack<T>::isEmpty()
{
    return (top == -1); // Return true if top is at -1
}

// Function to display the elements in the stack
template <class T>
void Stack<T>::display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << S[i] << " | " << flush; // Print each element
    }
    cout << endl;
}

// Function to get the top element of the stack
template <class T>
T Stack<T>::stackTop()
{
    if (isEmpty())
    {
        return -1; // Return -1 if stack is empty
    }
    return S[top]; // Return the top element
}

int main()
{
    // Array of elements to be pushed onto the stack
    int A[] = {1, 3, 5, 7, 9};

    // Create a stack with size equal to the number of elements in array A
    Stack<int> stk(sizeof(A) / sizeof(A[0]));

    // Populate stack with array elements
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        stk.push(A[i]);
    }

    // Attempt to push an element to a full stack (Overflow scenario)
    stk.push(11);

    // Check if the stack is full
    cout << "Stack full: " << stk.isFull() << endl;

    // Display stack elements
    cout << "Stack: " << flush;
    stk.display();

    // Peek at various positions
    cout << "Peek at 0th: " << stk.peek(0) << endl;
    cout << "Peek at 3rd: " << stk.peek(3) << endl;
    cout << "Peek at 10th: " << stk.peek(10) << endl;

    // Get the top element of the stack
    cout << "Top element: " << stk.stackTop() << endl;

    // Pop out elements from stack and display them
    cout << "Popped out elements: " << flush;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;

    // Attempt to pop from an empty stack (Underflow scenario)
    stk.pop();

    // Check if the stack is empty
    cout << "Stack empty: " << stk.isEmpty() << endl;

    return 0;
}
