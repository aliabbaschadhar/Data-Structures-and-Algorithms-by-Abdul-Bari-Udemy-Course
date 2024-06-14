#include <iostream>
using namespace std;

// Define a Node class to represent each element in the stack
class Node
{
public:
    int data;
    Node *next;
};

// Define a Stack class to manage the stack operations
class Stack
{
private:
    Node *top;

public:
    // Constructor to initialize the stack
    Stack()
    {
        top = nullptr;
    }

    // Destructor to free the memory when the stack is destroyed
    ~Stack()
    {
        Node *p = top;
        while (p)
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }

    // Function to push an element onto the stack
    void push(int x)
    {
        Node *t = new Node;
        if (t == nullptr)
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    // Function to pop an element from the stack
    int pop()
    {
        Node *p;
        int x = -1;
        if (top == nullptr)
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            p = top;
            x = p->data;
            top = top->next;
            delete p;
        }
        return x;
    }

    // Function to peek at the element at a specific index in the stack
    int peek(int index)
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            Node *p = top;

            for (int i = 0; p != nullptr && i < index - 1; i++)
            {
                p = p->next;
            }

            if (p != nullptr)
            {
                return p->data;
            }
            else
            {
                return -1;
            }
        }
    }

    // Function to check if the stack is empty
    int isEmpty()
    {
        return top ? 0 : 1;
    }

    // Function to check if the stack is full
    int isFull()
    {
        Node *t = new Node;
        int r = t ? 1 : 0;
        delete t;
        return r;
    }

    // Function to get the top element of the stack
    int stackTop()
    {
        if (top)
        {
            return top->data;
        }
        return -1;
    }
};

int main()
{
    // Define an array of elements to populate the stack
    int A[] = {1, 3, 5, 7, 9};

    // Create a new stack
    Stack stk;

    // Populate the stack with elements from the array
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        stk.push(A[i]);
    }

    // Peek at the element at the 3rd index in the stack
    cout << "Stack peek at 3rd: " << stk.peek(3) << endl;

    // Peek at the element at the 10th index in the stack (which does not exist)
    cout << "Stack peek at 10th: " << stk.peek(10) << endl;

    // Get the top element of the stack
    cout << "Stack top: " << stk.stackTop() << endl;

    // Check if the stack is full
    cout << "Stack full: " << stk.isFull() << endl;

    // Check if the stack is empty
    cout << "Stack empty: " << stk.isEmpty() << endl;

    // Pop out elements from the stack
    cout << "Popped: " << flush;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;

    // Attempt to pop an element from an empty stack (underflow)
    cout << stk.pop() << endl;

    return 0;
}