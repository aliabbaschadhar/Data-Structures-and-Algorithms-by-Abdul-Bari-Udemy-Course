#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    Node *lchild; // Pointer to the left child
    int data;     // Data of the node
    Node *rchild; // Pointer to the right child
};

class BST
{
private:
    Node *root; // Pointer to the root of the BST

public:
    BST() { root = nullptr; }                  // Constructor to initialize the root to nullptr
    Node *getRoot() { return root; }           // Getter for root
    void iInsert(int key);                     // Iterative insert method
    void Inorder(Node *p);                     // Method for inorder traversal
    Node *iSearch(int key);                    // Iterative search method
    Node *rInsert(Node *p, int key);           // Recursive insert method
    Node *rSearch(Node *p, int key);           // Recursive search method
    Node *Delete(Node *p, int key);            // Delete method
    int Height(Node *p);                       // Method to calculate height of the tree
    Node *InPre(Node *p);                      // Method to find inorder predecessor
    Node *InSucc(Node *p);                     // Method to find inorder successor
    void createFromPreorder(int pre[], int n); // Method to create BST from preorder traversal
};

void BST::iInsert(int key)
{
    Node *t = root; // Temporary pointer for traversal
    Node *p;        // Pointer to the newly created node
    Node *r;        // Pointer to keep track of the parent node

    // Case when the root is empty
    if (root == nullptr)
    {
        p = new Node;  // Create a new node
        p->data = key; // Assign data to the new node
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p; // Make the new node the root
        return;
    }

    // Traverse the tree to find the insert location
    while (t != nullptr)
    {
        r = t; // Keep track of the parent node
        if (key < t->data)
        {
            t = t->lchild; // Move to the left child
        }
        else if (key > t->data)
        {
            t = t->rchild; // Move to the right child
        }
        else
        {
            return; // Key already exists in the tree
        }
    }

    // Now t points at nullptr and r points at the insert location
    p = new Node;  // Create a new node
    p->data = key; // Assign data to the new node
    p->lchild = nullptr;
    p->rchild = nullptr;

    if (key < r->data)
    {
        r->lchild = p; // Insert as left child
    }
    else
    {
        r->rchild = p; // Insert as right child
    }
}

void BST::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);               // Traverse left subtree
        cout << p->data << ", " << flush; // Visit node
        Inorder(p->rchild);               // Traverse right subtree
    }
}

Node *BST::iSearch(int key)
{
    Node *t = root; // Temporary pointer for traversal
    while (t != nullptr)
    {
        if (key == t->data)
        {
            return t; // Node found
        }
        else if (key < t->data)
        {
            t = t->lchild; // Move to the left child
        }
        else
        {
            t = t->rchild; // Move to the right child
        }
    }
    return nullptr; // Node not found
}

Node *BST::rInsert(Node *p, int key)
{
    Node *t;
    if (p == nullptr)
    {
        t = new Node; // Create a new node
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t; // Return the new node
    }

    if (key < p->data)
    {
        p->lchild = rInsert(p->lchild, key); // Recursively insert in the left subtree
    }
    else if (key > p->data)
    {
        p->rchild = rInsert(p->rchild, key); // Recursively insert in the right subtree
    }
    return p; // Return the (possibly new) root of the subtree
}

Node *BST::rSearch(Node *p, int key)
{
    if (p == nullptr)
    {
        return nullptr; // Node not found
    }

    if (key == p->data)
    {
        return p; // Node found
    }
    else if (key < p->data)
    {
        return rSearch(p->lchild, key); // Recursively search in the left subtree
    }
    else
    {
        return rSearch(p->rchild, key); // Recursively search in the right subtree
    }
}

Node *BST::Delete(Node *p, int key)
{
    Node *q;

    // Base case: if the tree is empty
    if (p == nullptr)
    {
        return nullptr;
    }

    // Case: the node to be deleted is a leaf node
    if (p->lchild == nullptr && p->rchild == nullptr)
    {
        if (p == root)
        {
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    // Recursively search for the node to delete in the left subtree
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    // Recursively search for the node to delete in the right subtree
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    // Found the node to be deleted
    else
    {
        // Case: the node has two children
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);                   // Find the in-order predecessor
            p->data = q->data;                      // Replace the node's data with the predecessor's data
            p->lchild = Delete(p->lchild, q->data); // Delete the predecessor
        }
        else
        {
            q = InSucc(p->rchild);                  // Find the in-order successor
            p->data = q->data;                      // Replace the node's data with the successor's data
            p->rchild = Delete(p->rchild, q->data); // Delete the successor
        }
    }
    return p; // Return the (possibly new) root of the subtree
}

int BST::Height(Node *p)
{
    int x;
    int y;
    if (p == nullptr)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1; // Return the height of the subtree
}

Node *BST::InPre(Node *p)
{
    while (p && p->rchild != nullptr)
    {
        p = p->rchild; // Move to the rightmost child
    }
    return p;
}

Node *BST::InSucc(Node *p)
{
    while (p && p->lchild != nullptr)
    {
        p = p->lchild; // Move to the leftmost child
    }
    return p;
}

void BST::createFromPreorder(int *pre, int n)
{
    // Create root node
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = nullptr;
    root->rchild = nullptr;

    // Iterative steps
    Node *t;
    Node *p = root;
    stack<Node *> stk;

    while (i < n)
    {
        // Left child case
        if (pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            stk.push(p); // Push the current node to stack
            p = t;
        }
        else
        {
            // Right child cases
            if (pre[i] > p->data && pre[i] < (stk.empty() ? 32767 : stk.top()->data))
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.top(); // Pop from stack
                stk.pop();
            }
        }
    }
}

int main()
{
    BST bst;

    // Iterative insert
    bst.iInsert(10);
    bst.iInsert(5);
    bst.iInsert(20);
    bst.iInsert(8);
    bst.iInsert(30);

    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;

    // Iterative search
    Node *temp = bst.iSearch(2);
    if (temp != nullptr)
    {
        cout << temp->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    // Recursive search
    temp = bst.rSearch(bst.getRoot(), 20);
    if (temp != nullptr)
    {
        cout << temp->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    // Recursive insert
    bst.rInsert(bst.getRoot(), 50);
    bst.rInsert(bst.getRoot(), 70);
    bst.rInsert(bst.getRoot(), 1);
    bst.Inorder(bst.getRoot());
    cout << endl;

    // Inorder predecessor and inorder successor
    BST bs;
    bs.iInsert(5);
    bs.iInsert(2);
    bs.iInsert(8);
    bs.iInsert(7);
    bs.iInsert(9);
    bs.iInsert(1);

    temp = bs.InPre(bs.getRoot());
    cout << "InPre: " << temp->data << endl;

    temp = bs.InSucc(bs.getRoot());
    cout << "InSucc: " << temp->data << endl;

    bs.Inorder(bs.getRoot());
    cout << endl;

    // Delete
    bs.Delete(bs.getRoot(), 5);
    bs.Inorder(bs.getRoot());
    cout << endl;

    // BST from Preorder traversal
    cout << "BST from Preorder: " << flush;
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre) / sizeof(pre[0]);

    BST b;
    b.createFromPreorder(pre, n);
    b.Inorder(b.getRoot());
    cout << endl;

    return 0;
}
