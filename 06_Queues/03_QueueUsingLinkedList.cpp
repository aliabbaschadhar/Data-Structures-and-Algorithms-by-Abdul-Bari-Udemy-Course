#include <iostream>

using namespace std;

// Node class to represent each element in the queue
class Node
{
public:
    int data;   // Data of the node
    Node *next; // Pointer to the next node
};

// Queue class to implement queue operations using linked list
class Queue
{
private:
    Node *front; // Pointer to the front of the queue
    Node *rear;  // Pointer to the rear of the queue

public:
    Queue();             // Constructor to initialize the queue
    ~Queue();            // Destructor to clean up memory
    void enqueue(int x); // Add an element to the queue
    int dequeue();       // Remove an element from the queue
    bool isEmpty();      // Check if the queue is empty
    void display();      // Display the elements in the queue
};

// Constructor to initialize an empty queue
Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

// Function to add an element to the queue
void Queue::enqueue(int x)
{
    Node *t = new Node; // Create a new node
    if (t == nullptr)
    {
        cout << "Queue Overflow" << endl; // Check if memory allocation fails
    }
    else
    {
        t->data = x;       // Set the data
        t->next = nullptr; // Set the next pointer to null
        if (front == nullptr)
        {
            front = t; // If queue is empty, front and rear point to the new node
            rear = t;
        }
        else
        {
            rear->next = t; // Otherwise, add the new node at the rear
            rear = t;       // Move rear to the new node
        }
    }
}

// Function to remove an element from the queue
int Queue::dequeue()
{
    int x = -1;
    Node *p;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl; // Check if queue is empty
    }
    else
    {
        p = front;           // Point to the front node
        front = front->next; // Move front to the next node
        x = p->data;         // Retrieve the data
        delete p;            // Delete the old front node
    }
    return x;
}

// Function to check if the queue is empty
bool Queue::isEmpty()
{
    if (front == nullptr)
    {
        return true; // Return true if front is null
    }
    return false;
}

// Destructor to clean up the queue
Queue::~Queue()
{
    Node *p = front;
    while (front)
    {
        front = front->next; // Move front to the next node
        delete p;            // Delete the old front node
        p = front;           // Move p to the new front
    }
}

// Function to display the elements in the queue
void Queue::display()
{
    Node *p = front;
    while (p)
    {
        cout << p->data << flush; // Print the data
        p = p->next;              // Move to the next node
        if (p != nullptr)
        {
            cout << " <- " << flush; // Print the arrow if not the last element
        }
    }
    cout << endl;
}

int main()
{
    // Array of elements to be enqueued
    int A[] = {1, 3, 5, 7, 9};

    // Create a queue
    Queue q;

    // Enqueue elements
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        q.enqueue(A[i]);
    }

    // Display the queue
    q.display();

    // Dequeue elements
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        q.dequeue();
    }

    // Attempt to dequeue from an empty queue (Underflow scenario)
    q.dequeue();

    return 0;
}
