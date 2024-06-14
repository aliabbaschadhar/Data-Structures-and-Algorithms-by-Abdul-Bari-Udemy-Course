#include <iostream>
using namespace std;

class Queue
{
private:
    int size;  // Maximum size of the queue
    int front; // Index of the front element in the queue
    int rear;  // Index of the rear element in the queue
    int *Q;    // Pointer to the array holding queue elements

public:
    // Constructor to initialize the queue with a given size
    Queue(int size) : size(size)
    {
        front = -1;        // Initialize front index to -1 (empty queue)
        rear = -1;         // Initialize rear index to -1 (empty queue)
        Q = new int[size]; // Dynamically allocate memory for the queue array
    }

    // Destructor to deallocate the dynamically allocated memory
    ~Queue()
    {
        delete[] Q;
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return rear == size - 1 ? true : false;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == rear ? true : false;
    }

    // Function to add an element to the queue
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl; // Print message if the queue is full
        }
        else
        {
            rear++;          // Increment the rear index
            Q[rear] = value; // Add the value to the rear of the queue
        }
    }

    // Function to remove an element from the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl; // Print message if the queue is empty
            return -1;                        // Return a sentinel value indicating the queue is empty
        }
        else
        {
            front++;         // Increment the front index
            return Q[front]; // Return the value at the front of the queue
        }
    }

    // Function to display the elements of the queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl; // Print message if the queue is empty
        }
        else
        {
            for (int i = front + 1; i <= rear; i++)
            {
                cout << Q[i] << flush; // Print each element in the queue
                if (i < rear)
                {
                    cout << " <- " << flush; // Print arrow between elements
                }
            }
            cout << endl; // Add newline for better formatting
        }
    }
};

int main()
{
    int A[] = {2, 3, 5, 1, 5, 6};        // Array of elements to be added to the queue
    Queue que(sizeof(A) / sizeof(A[0])); // Create a queue with size equal to the number of elements in A

    // Enqueue each element of array A into the queue
    for (int i : A)
    {
        que.enqueue(i);
    }

    // Dequeue an element from the queue and print it
    cout << "Element removed is : " << que.dequeue() << endl;

    // Display the remaining elements in the queue
    que.display();

    return 0;
}
