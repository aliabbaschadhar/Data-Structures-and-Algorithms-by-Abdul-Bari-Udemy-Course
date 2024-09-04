#include <iostream>
#include <cstdlib>

// Define a class for the Node structure
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the linked list

    // Constructor to initialize the node with given data
    Node(int value) : data(value), next(nullptr) {}
};

// Define a class for the Hash Table
class HashTable
{
private:
    static const int TABLE_SIZE = 10; // Size of the hash table (number of slots)
    Node **table;                     // Array of pointers to Node, representing each slot in the hash table

public:
    // Constructor to initialize the hash table
    HashTable()
    {
        // Allocate memory for the table array
        table = new Node *[TABLE_SIZE];

        // Initialize each slot in the table to nullptr (empty)
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            table[i] = nullptr;
        }
    }

    // Destructor to free the memory allocated for the hash table
    ~HashTable()
    {
        // Iterate over each slot in the table
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            Node *current = table[i]; // Start at the head of the linked list for this slot
            while (current != nullptr)
            {
                // Store the next node before deleting the current one
                Node *next = current->next;
                delete current; // Free the memory for the current node
                current = next; // Move to the next node
            }
        }
        delete[] table; // Free the memory for the table array
    }

    // Hash function to map the key to an index in the table
    int hash(int key) const
    {
        // Use modulo operation to ensure the index is within the bounds of the table
        return key % TABLE_SIZE;
    }

    // Insert a key into the hash table while maintaining sorted order
    void insert(int key)
    {
        int index = hash(key);            // Determine the slot where the key should be inserted
        insertSorted(&table[index], key); // Insert the key into the sorted linked list at this slot
    }

    // Helper function to insert a key into the sorted linked list
    void insertSorted(Node **head, int key)
    {
        Node *newNode = new Node(key); // Create a new node with the given key

        // If the linked list is empty, set the new node as the head
        if (*head == nullptr)
        {
            *head = newNode;
        }
        else
        {
            Node *current = *head;    // Start at the head of the linked list
            Node *previous = nullptr; // Keep track of the previous node

            // Traverse the linked list until we find the correct position for the new node
            while (current != nullptr && current->data < key)
            {
                // As tail pointer previous is following current
                previous = current;      // Update previous node
                current = current->next; // Move to the next node
            }

            // If the new node should be at the head of the list
            if (current == *head)
            {
                newNode->next = *head; // Set the next pointer of the new node to the current head
                *head = newNode;       // Update the head to point to the new node
            }
            else
            {
                // Insert the new node between previous and current nodes
                newNode->next = previous->next; // Set the next pointer of the new node
                previous->next = newNode;       // Update the next pointer of the previous node
            }
        }
    }

    // Search for a key in the hash table
    Node *search(int key) const
    {
        int index = hash(key);                  // Determine the slot where the key might be
        return searchInList(table[index], key); // Search for the key in the linked list at this slot
    }

    // Helper function to search for a key in the linked list
    Node *searchInList(Node *head, int key) const
    {
        while (head != nullptr)
        {
            if (head->data == key)
            { // If the key is found, return the node
                return head;
            }
            head = head->next; // Move to the next node in the list
        }
        return nullptr; // Key not found, return nullptr
    }
};

int main()
{
    HashTable hashTable; // Create an instance of the HashTable class

    // Insert keys into the hash table
    hashTable.insert(12);
    hashTable.insert(22);
    hashTable.insert(42);

    // Search for a key
    Node *temp = hashTable.search(21);
    if (temp != nullptr)
    {
        std::cout << "Key found: " << temp->data << std::endl;
    }
    else
    {
        std::cout << "Key not found" << std::endl;
    }

    return 0;
}