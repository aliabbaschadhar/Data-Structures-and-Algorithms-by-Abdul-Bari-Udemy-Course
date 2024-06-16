#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Node class to represent each node in the tree
class Node
{
public:
    Node *leftChild;  // Pointer to the left child
    int data;         // Data stored in the node
    Node *rightChild; // Pointer to the right child

    Node(){};      // Default constructor
    Node(int data) // Constructor with data parameter
    {
        this->data = data;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

// Tree class to represent the binary tree
class Tree
{
private:
    Node *root; // Pointer to the root of the tree

public:
    Tree();                                                                             // Constructor to initialize root
    void createTree();                                                                  // Function to create a tree
    void PreOrder(Node *p);                                                             // Recursive pre-order traversal
    void PreOrder() { PreOrder(root); }                                                 // Public interface for pre-order traversal
    void Inorder(Node *p);                                                              // Recursive in-order traversal
    void Inorder() { Inorder(root); }                                                   // Public interface for in-order traversal
    void Postorder(Node *p);                                                            // Recursive post-order traversal
    void Postorder() { Postorder(root); }                                               // Public interface for post-order traversal
    void Levelorder(Node *p);                                                           // Level-order traversal
    void Levelorder() { Levelorder(root); }                                             // Public interface for level-order traversal
    int Height(Node *p);                                                                // Function to calculate the height of the tree
    int Height() { return Height(root); }                                               // Public interface for height calculation
    void iterativePreorder(Node *p);                                                    // Iterative pre-order traversal
    void iterativePreorder() { iterativePreorder(root); }                               // Public interface for iterative pre-order traversal
    void iterativeInorder(Node *p);                                                     // Iterative in-order traversal
    void iterativeInorder() { iterativeInorder(root); }                                 // Public interface for iterative in-order traversal
    void iterativePostorder(Node *p);                                                   // Iterative post-order traversal
    void iterativePostorder() { iterativePostorder(root); }                             // Public interface for iterative post-order traversal
    Node *generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd); // Generate tree from inorder and preorder traversals
};

// Constructor to initialize root to nullptr
Tree::Tree()
{
    root = nullptr;
}

// Function to create a tree using level-order input
void Tree::createTree()
{
    Node *p, *t;
    int x;
    queue<Node *> q; // Queue to hold nodes for level-order traversal
    root = new Node;
    cout << "Enter root data: ";
    cin >> x;
    root->data = x;
    root->leftChild = root->rightChild = nullptr;
    q.emplace(root); // Insert the root node into the queue

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        // Input left child
        cout << "Enter left child value of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftChild = t->rightChild = nullptr;
            p->leftChild = t;
            q.emplace(t); // Insert the left child node into the queue
        }

        // Input right child
        cout << "Enter right child value of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftChild = t->rightChild = nullptr;
            p->rightChild = t;
            q.emplace(t); // Insert the right child node into the queue
        }
    }
}

// Recursive pre-order traversal (NLR)
void Tree::PreOrder(Node *p)
{
    if (p)
    {
        cout << p->data << ", " << flush;
        PreOrder(p->leftChild);
        PreOrder(p->rightChild);
    }
}

// Recursive in-order traversal (LNR)
void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->leftChild);
        cout << p->data << ", " << flush;
        Inorder(p->rightChild);
    }
}

// Recursive post-order traversal (LRN)
void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->leftChild);
        Postorder(p->rightChild);
        cout << p->data << ", " << flush;
    }
}

// Level-order traversal
void Tree::Levelorder(Node *p)
{
    queue<Node *> q;
    cout << root->data << ", ";
    q.emplace(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();

        if (p->leftChild)
        {
            cout << p->leftChild->data << ", ";
            q.emplace(p->leftChild);
        }
        if (p->rightChild)
        {
            cout << p->rightChild->data << ", ";
            q.emplace(p->rightChild);
        }
    }
}

// Function to calculate the height of the tree
int Tree::Height(Node *p)
{
    int left = 0;
    int right = 0;
    if (p == nullptr)
    {
        return 0;
    }
    left = Height(p->leftChild);
    right = Height(p->rightChild);

    if (left > right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}

// Iterative pre-order traversal
void Tree::iterativePreorder(Node *p)
{
    stack<Node *> stk;
    while (p != nullptr || !stk.empty())
    {
        if (p != nullptr)
        {
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->leftChild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            p = p->rightChild;
        }
    }
    cout << endl;
}

// Iterative in-order traversal
void Tree::iterativeInorder(Node *p)
{
    stack<Node *> stk;
    while (p || !stk.empty())
    {
        if (p != nullptr)
        {
            stk.emplace(p);
            p = p->leftChild;
        }
        else
        {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rightChild;
        }
    }
    cout << endl;
}

// Iterative post-order traversal
void Tree::iterativePostorder(Node *p)
{
    stack<long int> stk;
    long int temp;
    while (p || !stk.empty())
    {
        if (p)
        {
            stk.emplace((long int)p);
            p = p->leftChild;
        }
        else
        {
            temp = stk.top();
            stk.pop();
            if (temp > 0)
            {
                stk.emplace(-temp);
                p = ((Node *)temp)->rightChild;
            }
            else
            {
                cout << ((Node *)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

// Helper function to find the index of a value in inorder array
int searchInorder(int inorder[], int inStart, int inEnd, int currentVal)
{
    for (int i = inStart; i <= inEnd; i++)
    {
        if (currentVal == inorder[i])
        {
            return i;
        }
    }
    return -1;
}

// Function to generate tree from inorder and preorder traversals
Node *Tree::generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd)
{
    static int preIndex = 0;

    if (inStart > inEnd)
    {
        return nullptr;
    }

    Node *node = new Node(preorder[preIndex++]);

    if (inStart == inEnd)
    {
        return node;
    }

    int pos = searchInorder(inorder, inStart, inEnd, node->data);

    node->leftChild = generateFromTraversal(inorder, preorder, inStart, pos - 1);
    node->rightChild = generateFromTraversal(inorder, preorder, pos + 1, inEnd);

    return node;
}

int main()
{
    Tree bt;

    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    // Generate tree from given inorder and preorder traversals
    Node *T = bt.generateFromTraversal(inorder, preorder, 0, sizeof(inorder) / sizeof(preorder[0]) - 1);

    // Perform pre-order traversal on the generated tree
    bt.PreOrder(T);

    /* Uncomment the following lines to create tree using level-order input
    bt.createTree();
    cout << endl;

    cout << "Preorder: " << flush;
    bt.PreOrder();
    cout << endl;

    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;

    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;

    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;

    cout << "Height: " << bt.Height() << endl; */

    return 0;
}
