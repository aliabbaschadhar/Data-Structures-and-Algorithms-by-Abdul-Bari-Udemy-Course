#include <iostream>
#include <limits.h>

using namespace std;

// Node class represents each element in the linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list

    // Constructor to initialize a node with a given value
    Node(int value = 0)
    {
        data = value;
        next = nullptr;
    }
};

// LinkedList class encapsulates operations on the linked list
class LinkedList
{
private:
    Node *first, *second, *Head; // Pointers to different nodes for various operations

public:
    // Constructor to initialize an empty linked list
    LinkedList()
    {
        first = nullptr;
        second = nullptr;
        Head = nullptr;
    }

    // Getter methods to access private members
    Node *getfirst()
    {
        return first;
    }

    Node *getSecond()
    {
        return second;
    }

    Node *getHead()
    {
        return Head;
    }

    // Create a linked list from an array of integers
    // A - array of integers
    // n - number of elements in the array
    void Create(int A[], int n)
    {
        Node *t, *last;
        // Create the first node with the first element of the array
        first = new Node(A[0]);
        first->next = nullptr;
        last = first;

        // Loop through the array starting from the second element
        // and create subsequent nodes, linking them to the last node
        for (int i = 1; i < n; i++)
        {
            t = new Node(A[i]);
            t->next = nullptr;
            last->next = t;
            last = t;
        }
    }

    // Display the linked list iteratively
    void display(Node *p)
    {
        p = first;
        // Traverse the linked list and print each node's data
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    // Recursively display the linked list in reverse order
    void rDisplay(Node *p)
    {
        if (p != nullptr)
        {
            // First, call the function recursively for the next node
            rDisplay(p->next);
            // Then, print the current node's data
            cout << p->data << " ";
        }
    }

    // Calculate the length of the linked list iteratively
    int Length()
    {
        Node *p = first;
        int count = 0;
        // Traverse the linked list and count the nodes
        while (p != nullptr)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    // Calculate the length of the linked list recursively (version 1)
    int rLength1(Node *p)
    {
        if (p != nullptr)
        {
            // Return 1 plus the length of the remaining list
            return rLength1(p->next) + 1;
        }
        else
        {
            return 0;
        }
    }

    // Calculate the length of the linked list recursively (version 2)
    int rLength2(Node *p)
    {
        if (p)
        {
            // Return 1 plus the length of the remaining list
            return rLength2(p->next) + 1;
        }
        else
        {
            return 0;
        }
    }

    // Calculate the sum of all elements in the linked list iteratively
    int Sum()
    {
        Node *p = first;
        int sum = 0;
        // Traverse the linked list and add each node's data to sum
        while (p != nullptr)
        {
            sum += p->data;
            p = p->next;
        }
        return sum;
    }

    // Calculate the sum of all elements in the linked list recursively
    int rSum(Node *p)
    {
        if (p != nullptr)
        {
            // Return the sum of the current node's data and the sum of the remaining list
            return rSum(p->next) + p->data;
        }
        else
        {
            return 0;
        }
    }

    // Find the maximum element in the linked list iteratively
    int Max()
    {
        Node *p = first;
        int max = INT_MIN;
        // Traverse the linked list and update max if current node's data is greater
        while (p != nullptr)
        {
            if (p->data > max)
            {
                max = p->data;
            }
            p = p->next;
        }
        return max;
    }

    // Find the maximum element in the linked list recursively
    int rMax(Node *p)
    {
        int x = 0;
        if (p == nullptr)
        {
            // Base case: if the list is empty, return the smallest possible integer
            return INT_MIN;
        }
        // Recursively find the maximum in the remaining list
        x = rMax(p->next);
        // Return the maximum between the current node's data and the maximum of the remaining list
        return x > p->data ? x : p->data;
    }

    // Search for an element in the linked list iteratively
    Node *Search(Node *p, int key)
    {
        // Traverse the list until the end
        while (p != nullptr)
        {
            // If the key is found, return the pointer to the node
            if (key == p->data)
            {
                return p;
            }
            p = p->next;
        }
        // If the key is not found, return nullptr
        return nullptr;
    }

    // Recursively search for an element in the linked list
    Node *rSearch(Node *p, int key)
    {
        if (p == nullptr)
        {
            // Base case: if the list is empty, return nullptr
            return nullptr;
        }
        // If the key is found, return the pointer to the node
        if (key == p->data)
        {
            return p;
        }
        // Otherwise, recursively search the remaining list
        return rSearch(p->next, key);
    }

    // Move found node to the head of the list to improve search efficiency
    Node *improvedSearch(Node *p, int key)
    {
        Node *q = nullptr;
        // Traverse the list until the end
        while (p != nullptr)
        {
            // If the key is found
            if (p->data == key)
            {
                // Move the node to the head if it's not already the first node
                if (q != nullptr)
                {
                    q->next = p->next;
                    p->next = first;
                    first = p;
                }
                return p;
            }
            q = p;
            p = p->next;
        }
        // If the key is not found, return nullptr
        return nullptr;
    }

    // Insert an element at a specified index
    void Insert(int index, int x)
    {
        Node *t, *p;
        // Check for invalid index
        if (index < 0 || index > Length())
        {
            cout << "Invalid Index";
            return;
        }
        t = new Node(x);
        // If inserting at the beginning
        if (index == 0)
        {
            t->next = first;
            first = t;
        }
        else
        {
            // Traverse the list to find the correct position
            p = first;
            for (int i = 0; i < index - 1 && p != nullptr; i++)
            {
                p = p->next;
            }
            // Insert the node at the correct position
            if (p)
            {
                t->next = p->next;
                p->next = t;
            }
        }
    }

    // Insert an element at the end of the list
    void InsertLast(int x)
    {
        Node *t = new Node(x);
        // If the list is empty, set the new node as the first node
        if (first == nullptr)
        {
            first = t;
        }
        else
        {
            // Traverse to the end of the list
            Node *last = first;
            while (last->next != nullptr)
            {
                last = last->next;
            }
            // Insert the new node at the end
            last->next = t;
        }
    }

    // Insert an element into a sorted list
    void insertSorted(int x)
    {
        Node *p = first, *q = nullptr, *t = new Node(x);
        // If the list is empty, set the new node as the first node
        if (first == nullptr)
        {
            first = t;
        }
        else
        {
            // Traverse the list to find the correct position
            while (p && x > p->data)
            {
                q = p;
                p = p->next;
            }
            // Insert the new node at the beginning if it is the smallest element
            if (p == first)
            {
                t->next = first;
                first = t;
            }
            else
            {
                // Insert the new node at the correct position
                t->next = q->next;
                q->next = t;
            }
        }
    }

    // Delete an element at a specified index
    int Delete(int index)
    {
        Node *p, *q = nullptr;
        int x = -1;
        // Check for invalid index
        if (index < 1 || index > Length())
        {
            return -1;
        }
        // If deleting the first node
        if (index == 1)
        {
            p = first;
            first = first->next;
            x = p->data;
            delete p;
        }
        else
        {
            // Traverse the list to find the correct position
            p = first;
            for (int i = 0; i < index - 1 && p != nullptr; i++)
            {
                q = p;
                p = p->next;
            }
            // Delete the node at the correct position
            if (p != nullptr)
            {
                q->next = p->next;
                x = p->data;
                delete p;
            }
        }
        return x;
    }

    // Check if the list is sorted
    bool isSorted()
    {
        int max = INT_MIN;
        Node *p = first;
        // Traverse the list and check if each node's data is greater than or equal to the previous node's data
        while (p != nullptr)
        {
            if (p->data < max)
            {
                return false;
            }
            max = p->data;
            p = p->next;
        }
        return true;
    }

    // Remove duplicate elements from a sorted list
    void removeDuplicate()
    {
        Node *p = first;
        Node *q = first->next;
        // Traverse the list
        while (q != nullptr)
        {
            // If the current node's data is equal to the next node's data, remove the next node
            if (p->data != q->data)
            {
                p = q;
                q = q->next;
            }
            else
            {
                p->next = q->next;
                delete q;
                q = p->next;
            }
        }
    }

    // Reverse the list by storing the data in an array and then reassigning it to the nodes
    void reverseData(int size)
    {
        Node *p = first;
        int i = 0;
        int arr[size];
        // Store the data in an array
        while (p != nullptr)
        {
            arr[i++] = p->data;
            p = p->next;
        }
        p = first;
        i--;
        // Reassign the data to the nodes in reverse order
        while (p != nullptr)
        {
            p->data = arr[i--];
            p = p->next;
        }
    }

    // Reverse the list using sliding pointers
    void reverseSlidingWindowOrSlidingPointers()
    {
        Node *p = first;
        Node *q = nullptr, *r = nullptr;
        // Traverse the list and reverse the links between nodes
        while (p != nullptr)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        first = q;
    }

    // Reverse the list recursively
    void reverseRecursion(Node *q, Node *p)
    {
        if (p != nullptr)
        {
            // Recursively reverse the remaining list
            reverseRecursion(p, p->next);
            p->next = q;
        }
        else
        {
            first = q;
        }
    }

    // Concatenate two linked lists
    Node *concatenate(LinkedList &l2)
    {
        if (first == nullptr)
        {
            first = l2.first;
        }
        else
        {
            // Traverse to the end of the first list
            Node *p = first;
            while (p->next != nullptr)
            {
                p = p->next;
            }
            // Link the end of the first list to the beginning of the second list
            p->next = l2.first;
        }
        return first;
    }

    // Merge two sorted linked lists into one sorted linked list
    void merge(LinkedList &l1, LinkedList &l2)
    {
        Node *p = l1.first;
        Node *q = l2.first;
        Node *lastMerged = nullptr;

        // Initialize the merged list with the smallest element
        if (p->data < q->data)
        {
            first = lastMerged = p;
            p = p->next;
            first->next = nullptr;
        }
        else
        {
            first = lastMerged = q;
            q = q->next;
            first->next = nullptr;
        }

        // Merge the remaining elements
        while (p != nullptr && q != nullptr)
        {
            if (p->data < q->data)
            {
                lastMerged->next = p;
                lastMerged = p;
                p = p->next;
                lastMerged->next = nullptr;
            }
            else
            {
                lastMerged->next = q;
                lastMerged = q;
                q = q->next;
                lastMerged->next = nullptr;
            }
        }

        // Attach the remaining elements from either list
        if (p != nullptr)
            lastMerged->next = p;
        if (q != nullptr)
            lastMerged->next = q;
    }

    // Check if there is a loop in the list
    bool isLoop()
    {
        Node *p = first, *q = first;
        // Use two pointers moving at different speeds to detect a loop
        do
        {
            p = p->next;
            q = q ? q->next : q;
            q = q ? q->next : q; // q should be assigned q if condition becomes false or true
        } while (p && q && p != q);

        // If pointers meet, there is a loop
        if (q == p)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Find the middle element of the list
    void middle()
    {
        Node *p, *q;
        p = q = first;
        // Use two pointers moving at different speeds to find the middle
        while (p != nullptr)
        {
            q = q->next;
            if (q != nullptr)
            {
                q = q->next;
            }
            if (q != nullptr)
            {
                p = p->next;
            }
        }
        cout << "Middle value is : " << p->data;
    }
};

int main()
{
    // Implementing the loop functions.
    LinkedList list1, list2, mergedList;
    int A[] = {10, 20, 40, 50, 60};
    list1.Create(A, 5);
    Node *t1, *t2;
    t1 = list1.getfirst()->next->next;             // Point to the third node
    t2 = list1.getfirst()->next->next->next->next; // Point to the last node
    t2->next = t1;                                 // Create a loop by linking the last node to the third node
    cout << list1.isLoop();                        // Check if the list has a loop

    // int B[] = {15, 18, 25, 30, 55};
    // list2.Create(B, 5);

    // mergedList.merge(list1, list2);
    // mergedList.display(mergedList.getfirst());

    // // Concatenate list2 to list1
    // list1.concatenate(list2);

    // // Traverse the concatenated list and print the data
    // Node *current = list1.getfirst();
    // while (current != nullptr) {
    //     cout << current->data << " ";
    //     current = current->next;
    // }
    // cout << endl;

    return 0;
}
