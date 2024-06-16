#include <iostream>
using namespace std;

// Node class representing each element in the doubly linked list
class Node
{
public:
    Node *prev; // Pointer to the previous node
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node
};

// DoublyLinkedList class containing methods to manipulate the doubly linked list
class DoublyLinkedList
{
private:
    Node *head; // Pointer to the head (first node) of the list

public:
    // Default constructor initializing an empty list
    DoublyLinkedList();

    // Constructor to create a list from an array
    DoublyLinkedList(int A[], int n);

    // Destructor to clean up memory
    ~DoublyLinkedList();

    // Display the list
    void Display();

    // Get the length of the list
    int Length();

    // Insert a node at a specific index
    void Insert(int index, int x);

    // Delete a node at a specific index
    int Delete(int index);

    // Reverse the list
    void Reverse();
};

// Default constructor initializing an empty list
DoublyLinkedList::DoublyLinkedList()
{
    head = new Node;
    head->prev = nullptr;
    head->data = 0;
    head->next = nullptr;
}

// Constructor to create a list from an array
DoublyLinkedList::DoublyLinkedList(int *A, int n)
{
    head = new Node;
    head->prev = nullptr;
    head->data = A[0];
    head->next = nullptr;
    Node *tail = head;

    // Create the list by linking nodes based on array elements
    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;
        t->prev = tail;
        t->data = A[i];
        t->next = tail->next; // tail->next is pointing to NULL
        tail->next = t;
        tail = t;
    }
}

// Display the list by traversing from head to end
void DoublyLinkedList::Display()
{
    Node *p = head;
    while (p != nullptr)
    {
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr)
        {
            cout << " <-> " << flush;
        }
    }
    cout << endl;
}

// Get the length of the list by counting nodes
int DoublyLinkedList::Length()
{
    int length = 0;
    Node *p = head;
    while (p != nullptr)
    {
        length++;
        p = p->next;
    }
    return length;
}

// Insert a node at a specific index
void DoublyLinkedList::Insert(int index, int x)
{
    if (index < 0 || index > Length())
    {
        return;
    }

    Node *p = head;
    Node *t = new Node;
    t->data = x;

    if (index == 0)
    {
        t->prev = nullptr;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

// Delete a node at a specific index
int DoublyLinkedList::Delete(int index)
{
    int x = -1;
    Node *p = head;

    if (index < 0 || index > Length())
    {
        return x;
    }

    if (index == 1)
    {
        head = head->next;
        if (head)
        {
            head->prev = nullptr;
        }
        x = p->data;
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
}

// Reverse the list by swapping next and prev pointers of each node
void DoublyLinkedList::Reverse()
{
    Node *p = head;
    Node *temp;
    while (p != nullptr)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;

        // If p is the new head, update the head pointer
        if (p && p->next == nullptr)
        {
            p->next = p->prev;
            p->prev = nullptr;
            head = p;
            break;
        }
    }
}

// Destructor to clean up memory by deleting all nodes
DoublyLinkedList::~DoublyLinkedList()
{
    Node *p = head;
    while (head)
    {
        head = head->next;
        delete p;
        p = head;
    }
}

int main()
{
    // Create a list from an array
    int A[]{1, 3, 5, 7, 9};
    DoublyLinkedList dll(A, sizeof(A) / sizeof(A[0]));
    cout << "Length: " << dll.Length() << endl;

    // Insert elements at specific indices
    dll.Insert(0, 11);
    dll.Insert(6, 13);
    dll.Display();

    // Delete elements from specific indices
    dll.Delete(1);
    dll.Delete(6);
    dll.Display();

    // Reverse the list
    dll.Reverse();
    dll.Display();

    return 0;
}
