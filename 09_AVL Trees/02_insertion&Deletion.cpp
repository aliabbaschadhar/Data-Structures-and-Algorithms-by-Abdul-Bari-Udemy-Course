#include <iostream>

using namespace std;

// Node class representing each node in the AVL tree
class Node
{
public:
    Node *lchild; // Left child pointer
    int data;     // Data stored in the node
    Node *rchild; // Right child pointer
    int height;   // Height of the node
};

// AVL tree class
class AVL
{
public:
    Node *root; // Root of the AVL tree

    // Constructor initializes the root to nullptr
    AVL() { root = nullptr; }

    // Helper methods for inserting/deleting nodes and balancing the tree
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *LLRotation(Node *p);
    Node *RRRotation(Node *p);
    Node *LRRotation(Node *p);
    Node *RLRotation(Node *p);
    Node *InPre(Node *p);
    Node *InSucc(Node *p);

    // Insert method
    Node *rInsert(Node *p, int key);

    // Traversal method
    void Inorder(Node *p);
    void Inorder() { Inorder(root); }
    Node *getRoot() { return root; }

    // Delete method
    Node *Delete(Node *p, int key);
};

// Method to calculate the height of a node
int AVL::NodeHeight(Node *p)
{
    int hl;
    int hr;

    // Calculate height of left and right children
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    // Return the maximum height between left and right children plus one
    return hl > hr ? hl + 1 : hr + 1;
}

// Method to calculate the balance factor of a node
int AVL::BalanceFactor(Node *p)
{
    int hl;
    int hr;

    // Calculate height of left and right children
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    // Return the difference between left and right heights
    return hl - hr;
}

// Left-Left (LL) Rotation
Node *AVL::LLRotation(Node *p)
{
    Node *pl = p->lchild;   // Left child of p
    Node *plr = pl->rchild; // Right child of pl

    pl->rchild = p;  // Make p the right child of pl
    p->lchild = plr; // Make plr the left child of p

    // Update heights
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root if necessary
    if (root == p)
    {
        root = pl;
    }
    return pl; // Return new root of the subtree
}

// Right-Right (RR) Rotation
Node *AVL::RRRotation(Node *p)
{
    Node *pr = p->rchild;   // Right child of p
    Node *prl = pr->lchild; // Left child of pr

    pr->lchild = p;  // Make p the left child of pr
    p->rchild = prl; // Make prl the right child of p

    // Update heights
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root if necessary
    if (root == p)
    {
        root = pr;
    }
    return pr; // Return new root of the subtree
}

// Left-Right (LR) Rotation
Node *AVL::LRRotation(Node *p)
{
    Node *pl = p->lchild;   // Left child of p
    Node *plr = pl->rchild; // Right child of pl

    pl->rchild = plr->lchild; // Make plr's left child the right child of pl
    p->lchild = plr->rchild;  // Make plr's right child the left child of p

    plr->lchild = pl; // Make pl the left child of plr
    plr->rchild = p;  // Make p the right child of plr

    // Update heights
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    // Update root if necessary
    if (p == root)
    {
        root = plr;
    }
    return plr; // Return new root of the subtree
}

// Right-Left (RL) Rotation
Node *AVL::RLRotation(Node *p)
{
    Node *pr = p->rchild;   // Right child of p
    Node *prl = pr->lchild; // Left child of pr

    pr->lchild = prl->rchild; // Make prl's right child the left child of pr
    p->rchild = prl->lchild;  // Make prl's left child the right child of p

    prl->rchild = pr; // Make pr the right child of prl
    prl->lchild = p;  // Make p the left child of prl

    // Update heights
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root if necessary
    if (root == p)
    {
        root = prl;
    }
    return prl; // Return new root of the subtree
}

// Inorder predecessor (rightmost node in left subtree)
Node *AVL::InPre(Node *p)
{
    while (p && p->rchild != nullptr)
    {
        p = p->rchild;
    }
    return p;
}

// Inorder successor (leftmost node in right subtree)
Node *AVL::InSucc(Node *p)
{
    while (p && p->lchild != nullptr)
    {
        p = p->lchild;
    }
    return p;
}

// Recursive insert method
Node *AVL::rInsert(Node *p, int key)
{
    Node *t;
    if (p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1; // Starting height from 1 onwards instead of 0
        return t;
    }

    if (key < p->data)
    {
        p->lchild = rInsert(p->lchild, key); // Insert in the left subtree
    }
    else if (key > p->data)
    {
        p->rchild = rInsert(p->rchild, key); // Insert in the right subtree
    }

    // Update height of the current node
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        return RLRotation(p);
    }

    return p; // Return the (possibly new) root of the subtree
}

// Inorder traversal method
void AVL::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);               // Traverse left subtree
        cout << p->data << ", " << flush; // Visit node
        Inorder(p->rchild);               // Traverse right subtree
    }
}

// Recursive delete method
Node *AVL::Delete(Node *p, int key)
{
    if (p == nullptr)
    {
        return nullptr;
    }

    // Node to be deleted found
    if (p->lchild == nullptr && p->rchild == nullptr)
    {
        if (p == root)
        {
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    // Traverse to find the node to delete
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        Node *q;
        if (NodeHeight(p->lchild) > NodeHeight(p->rchild))
        {
            q = InPre(p->lchild); // Find inorder predecessor
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild); // Find inorder successor
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    { // L1 Rotation
        return LLRotation(p);
    }
    else if (BalanceFactor(p

                           ) == 2 &&
             BalanceFactor(p->lchild) == -1)
    { // L-1 Rotation
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    { // R-1 Rotation
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    { // R1 Rotation
        return RLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0)
    { // L0 Rotation
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0)
    { // R0 Rotation
        return RRRotation(p);
    }

    return p; // Return the (possibly new) root of the subtree
}

int main()
{
    AVL tree;

    // Insert nodes into the AVL tree
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        tree.root = tree.rInsert(tree.root, A[i]);
    }

    // Inorder traversal of the AVL tree
    tree.Inorder();
    cout << endl;

    // Delete a node from the AVL tree
    tree.Delete(tree.root, 28);

    // Inorder traversal of the AVL tree after deletion
    tree.Inorder();
    cout << endl;

    return 0;
}
