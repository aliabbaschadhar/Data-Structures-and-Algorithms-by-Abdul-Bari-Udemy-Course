#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

// Define the Node class to represent elements in linked lists
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize the node
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Function to insert a node at the end of the linked list
void insert(Node **head, int value)
{
    // Create a new node with the given value
    Node *newNode = new Node(value);

    // If the list is empty, set the new node as the head
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }

    // Otherwise, traverse the list to find the last node
    Node *last = *head;
    while (last->next != nullptr)
    {
        last = last->next;
    }

    // Append the new node to the end of the list
    last->next = newNode;
}

// Function to delete and return the head of the linked list
int deleteNode(Node **head)
{
    // If the list is empty, return a sentinel value
    if (*head == nullptr)
    {
        return INT_MIN;
    }

    // Store the value of the head node
    int value = (*head)->data;

    // Store the current head in a temporary pointer
    Node *temp = *head;

    // Move the head to the next node
    *head = (*head)->next;

    // Delete the old head node
    delete temp;

    // Return the value of the deleted node
    return value;
}

// Function to find the maximum element in the array
int findMax(int arr[], int n)
{
    // Initialize max with the smallest possible integer value
    int max = INT_MIN;

    // Iterate through the array to find the maximum element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Return the maximum value found
    return max;
}

// Main bucket sort function
void bucketSort(int arr[], int n)
{
    // Step 1: Create empty buckets
    int max = findMax(arr, n);
    Node **Bins;
    Bins = new Node *[max + 1];

    // Initialize all buckets as empty
    for (int i = 0; i < max + 1; i++)
    {
        Bins[i] = nullptr;
    }

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++)
    {
        insert(&Bins[arr[i]], arr[i]);
    }

    // Step 3: Collect elements from buckets back into the array
    int j = 0;
    for (int i = 0; i < max + 1; i++)
    {
        while (Bins[i] != nullptr)
        {
            arr[j++] = deleteNode(&Bins[i]);
        }
    }

    // Step 4: Deallocate memory for bins
    delete[] Bins;
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int size = 10;
    int testArray[size] = {5, 2, 8, 1, 9, 3, 7, 6, 4, 0};

    cout << "Original array: ";
    printArray(testArray, size);

    bucketSort(testArray, size);

    cout << "Sorted array: ";
    printArray(testArray, size);

    return 0;
}