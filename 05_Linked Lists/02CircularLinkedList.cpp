#include <iostream>
using namespace std;

// Define a class for the Node in the circular linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list
    Node(int data = 0)
    {
        this->data = data;
        next = nullptr;
    }
};

// Define a class for the Circular Linked List
class CircularLinkedList
{
private:
    Node *head; // Pointer to the head of the list

public:
    // Constructor to initialize the list
    CircularLinkedList()
    {
        head = nullptr; // Initialize the head to nullptr
    }

    Node *getHead()
    {
        return head;
    }
    // Method to create the circular linked list from an array
    void create(int A[], int n)
    {
        Node *t, *last;        // Temporary node and last node in the list
        head = new Node(A[0]); // Create the head node
        head->next = head;     // Set the next pointer of the head node to itself
        last = head;           // Set the last node to the head node

        // Iterate through the array to create the list
        for (int i = 1; i < n; i++)
        {
            t = new Node(A[i]);   // Create a new node
            t->next = last->next; // Set the next pointer of the new node to the last node's next
            last->next = t;       // Set the last node's next to the new node
            last = t;             // Update the last node
        }
    }

    // Method to display the elements of the list
    void display()
    {
        Node *h = head; // Initialize a pointer to the head
        do
        {
            cout << h->data << " "; // Print the data of the current node
            h = h->next;            // Move to the next node
        } while (h != head); // Continue until we reach the head again
        cout << endl; // Print a newline
    }

    // Method to recursively display the elements of the list
    void rDisplay(Node *h)
    {
        static int flag = 0; // Flag to prevent infinite recursion
        if (h != head || flag == 0)
        {
            flag = 1;               // Set the flag
            cout << h->data << " "; // Print the data of the current node
            rDisplay(h->next);      // Recursively call the method
        }
        flag = 0; // Reset the flag
    }

    // Method to calculate the length of the list
    int length(Node *p)
    {
        int len = 0; // Initialize the length
        do
        {
            len++;       // Increment the length
            p = p->next; // Move to the next node
        } while (p != head); // Continue until we reach the head again
        return len; // Return the length
    }

    // Method to insert a new element at a specified index
    void insert(int index, int x)
    {
        Node *t; // Temporary node
        int i;   // Index for iteration
        if (index < 0 || index > length(head))
            return; // Return if the index is out of bounds

        if (index == 0)
        {
            t = new Node; // Create a new node
            t->data = x;  // Set the data of the new node
            if (head == nullptr)
            {
                head = t;          // Set the head to the new node
                head->next = head; // Set the next pointer of the head to itself
            }
            else
            {
                Node *temp = head; // Temporary pointer to the head
                while (temp->next != head)
                    temp = temp->next; // Move to the last node
                temp->next = t;        // Set the next pointer of the last node to the new node
                t->next = head;        // Set the next pointer of the new node to the head
                head = t;              // Set the head to the new node
            }
        }
        else
        {
            Node *p = head; // Initialize a pointer to the head
            for (i = 0; i < index - 1; i++)
                p = p->next;   // Move to the node before the insertion point
            t = new Node;      // Create a new node
            t->data = x;       // Set the data of the new node
            t->next = p->next; // Set the next pointer of the new node to the node after the insertion point
            p->next = t;       // Set the next pointer of the node before the insertion point to the new node
        }
    }

    // Method to delete an element at a specified index
    int del(int index)
    {
        Node *q;  // Temporary node
        int i, x; // Index and data to be deleted

        if (index < 0 || index > length(head))
            return -1; // Return if the index is out of bounds

        if (index == 1)
        {
            Node *temp = head; // Temporary pointer to the head
            while (temp->next != head)
                temp = temp->next; // Move to the last node
            x = head->data;        // Store the data of the head node
            if (head == temp)
            {
                delete head;    // Delete the head node
                head = nullptr; // Set the head to nullptr
            }
            else
            {
                temp->next = head->next; // Set the next pointer of the last node to the node after the head
                delete head;             // Delete the head node
                head = temp->next;       // Set the head to the node after the head
            }
        }
        else
        {
            Node *p = head; // Initialize a pointer to the head
            for (i = 0; i < index - 2; i++)
                p = p->next;   // Move to the node before the deletion point
            q = p->next;       // Store the node to be deleted
            p->next = q->next; // Set the next pointer of the node before the deletion point to the node after the deletion point
            x = q->data;       // Store the data of the node to be deleted
            delete q;          // Delete the node to be deleted
        }
        return x; // Return the data of the deleted node
    }
};

int main()
{
    CircularLinkedList list;   // Create a circular linked list
    int A[] = {2, 3, 4, 5, 6}; // Array of elements to be inserted
    list.create(A, 5);         // Create the list from the array

    list.del(8); // Delete an element at index 8

    list.rDisplay(list.getHead()); // Display the elements of the list

    return 0;
}