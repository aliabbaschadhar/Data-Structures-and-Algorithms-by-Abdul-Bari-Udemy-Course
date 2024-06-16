#include <iostream>

using namespace std;

class CircularQueue
{
private:
    int size;  // Maximum size of the circular queue
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int *Q;    // Pointer to the array representing the queue

public:
    CircularQueue(int size); // Constructor to initialize the queue
    ~CircularQueue();        // Destructor to clean up memory
    bool isFull();           // Check if the queue is full
    bool isEmpty();          // Check if the queue is empty
    void enqueue(int x);     // Add an element to the queue
    int dequeue();           // Remove an element from the queue
    void display();          // Display the elements in the queue
};

// Constructor to initialize the circular queue
CircularQueue::CircularQueue(int size)
{
    this->size = size;
    front = 0;
    rear = 0;
    Q = new int[size]; // Allocate memory for the queue
}

// Destructor to free the allocated memory
CircularQueue::~CircularQueue()
{
    delete[] Q;
}

// Check if the queue is empty
bool CircularQueue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

// Check if the queue is full
bool CircularQueue::isFull()
{
    if ((rear + 1) % size == front)
    {
        return true;
    }
    return false;
}

// Add an element to the queue
void CircularQueue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        rear = (rear + 1) % size; // Update rear index circularly
        Q[rear] = x;              // Insert element at rear
    }
}

// Remove an element from the queue
int CircularQueue::dequeue()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        front = (front + 1) % size; // Update front index circularly
        x = Q[front];               // Retrieve element from front
    }
    return x;
}

// Display the elements in the queue
void CircularQueue::display()
{
    int i = front + 1;
    do
    {
        cout << Q[i] << flush;
        if (i < rear)
        {
            cout << " <- " << flush;
        }
        i = (i + 1) % size; // Move to the next element circularly
    } while (i != (rear + 1) % size);
}

int main()
{
    // Array of elements to be enqueued
    int A[] = {1, 3, 5, 7, 9};

    // Create a circular queue with size one greater than the number of elements
    CircularQueue cq(sizeof(A) / sizeof(A[0]) + 1);

    // Enqueue elements
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        cq.enqueue(A[i]);
    }

    // Display the queue
    cq.display();
    cout << endl;

    // Attempt to enqueue an element in a full queue (Overflow scenario)
    cq.enqueue(10);

    // Dequeue elements
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        cq.dequeue();
    }

    // Attempt to dequeue from an empty queue (Underflow scenario)
    cq.dequeue();

    return 0;
}
