#include <iostream>
using namespace std;

#ifndef QueueCpp_h
#define QueueCpp_h

// Node class to represent each node in the queue
class Node
{
public:
    Node *leftChild;  // Pointer to the left child
    Node *rightChild; // Pointer to the right child
    int data;         // Data stored in the node
};

// Queue class to represent a queue of nodes
class Queue
{
private:
    int front; // Front index of the queue
    int rear;  // Rear index of the queue
    int size;  // Size of the queue
    Node **Q;  // Array of pointers to Node objects

public:
    // Constructors
    Queue() // Default constructor
    {
        front = rear = -1;    // Initialize front and rear to -1 (empty queue)
        size = 10;            // Default size of the queue is 10
        Q = new Node *[size]; // Allocate memory for the array of pointers
    }
    Queue(int size) : size(size) // Parameterized constructor
    {
        front = rear = -1;    // Initialize front and rear to -1 (empty queue)
        Q = new Node *[size]; // Allocate memory for the array of pointers
    }

    // Destructor
    ~Queue() // Destructor to deallocate memory
    {
        delete[] Q; // Deallocate memory allocated for the array of pointers
    }

    // Function to enqueue a node into the queue
    void enqueue(Node *x)
    {
        if (rear == size - 1) // If rear is at the last index, queue is full
        {
            cout << "Queue is full\n"; // Display error message
        }
        else
        {
            rear++;      // Increment rear index
            Q[rear] = x; // Add the node to the queue
        }
    }

    // Function to dequeue a node from the queue
    Node *dequeue()
    {
        Node *x = nullptr; // Initialize the dequeued node pointer
        if (front == rear) // If front and rear are equal, queue is empty
        {
            cout << "Queue is Empty\n"; // Display error message
        }
        else
        {
            x = Q[front + 1]; // Get the node at the front of the queue
            front++;          // Increment front index
        }
        return x; // Return the dequeued node
    }

    // Function to display the elements of the queue
    void Display()
    {
        for (int i = front + 1; i <= rear; i++) // Iterate through the queue elements
        {
            cout << Q[i]; // Display each element
        }
        cout << endl; // Move to the next line
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        if (front == rear) // If front and rear are equal, queue is empty
        {
            return true; // Return true
        }
        return false; // Return false otherwise
    }

    // Function to check if the queue is full
    bool isFull()
    {
        if (rear == size - 1) // If rear is at the last index, queue is full
        {
            return true; // Return true
        }
        return false; // Return false otherwise
    }
};

#endif
