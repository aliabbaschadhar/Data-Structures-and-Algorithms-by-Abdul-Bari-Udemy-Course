#include <iostream>
#include "QueueCpp.h" // Include the header file for the Queue class

class Tree
{
public:
    Node *root;                // Pointer to the root node of the tree
    Tree() { root = nullptr; } // Constructor to initialize root to nullptr
    void createTree();         // Function to create the tree
    void preOrder(Node *p);    // Function for pre-order traversal
    void inOrder(Node *p);     // Function for in-order traversal
    void postOrder(Node *p);   // Function for post-order traversal
};

// Function to create the tree
void Tree::createTree()
{
    root = new Node; // Allocate memory for the root node
    Node *p, *t;     // Pointers to nodes used for traversing and creating the tree
    int x;           // Variable to store user input
    Queue q(10);     // Create a queue with a size of 10

    // Create the root node
    cout << "Enter root value: ";
    cin >> x;
    root->data = x;
    root->leftChild = nullptr;
    root->rightChild = nullptr;

    // Enqueue the root node
    q.enqueue(root);

    // Loop until the queue is empty
    while (!q.isEmpty())
    {
        p = q.dequeue(); // Dequeue a node

        // Get the left child value from the user
        cout << "Enter left child value of " << p->data << " -> ";
        cin >> x;
        if (x != -1)
        {
            t = new Node; // Create a new node
            t->data = x;
            t->leftChild = nullptr;
            t->rightChild = nullptr;
            p->leftChild = t; // Link the new node as the left child
            q.enqueue(t);     // Enqueue the new node
        }

        // Get the right child value from the user
        cout << "Enter right child value of " << p->data << " -> ";
        cin >> x;
        if (x != -1)
        {
            t = new Node; // Create a new node
            t->data = x;
            t->leftChild = nullptr;
            t->rightChild = nullptr;
            p->rightChild = t; // Link the new node as the right child
            q.enqueue(t);      // Enqueue the new node
        }
    }
}

// Function for pre-order traversal (NLR)
void Tree::preOrder(Node *p)
{
    if (p != nullptr)
    {
        cout << p->data << " ";  // Visit the node
        preOrder(p->leftChild);  // Traverse the left subtree
        preOrder(p->rightChild); // Traverse the right subtree
    }
}

// Function for in-order traversal (LNR)
void Tree::inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->leftChild);  // Traverse the left subtree
        cout << p->data << " "; // Visit the node
        inOrder(p->rightChild); // Traverse the right subtree
    }
}

// Function for post-order traversal (LRN)
void Tree::postOrder(Node *p)
{
    if (p)
    {
        postOrder(p->leftChild);  // Traverse the left subtree
        postOrder(p->rightChild); // Traverse the right subtree
        cout << p->data << " ";   // Visit the node
    }
}

int main()
{
    Tree t;         // Create a tree object
    t.createTree(); // Create the tree
    cout << "PostOrder Traversal is: ";
    t.postOrder(t.root); // Perform post-order traversal
    cout << endl;

    return 0;
}
