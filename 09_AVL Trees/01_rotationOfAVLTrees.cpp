#include <iostream>

using namespace std;

// Node class to represent a node in the AVL tree
class Node
{
public:
    Node *lchild; // Left child
    int data;     // Data stored in the node
    Node *rchild; // Right child
    int height;   // Height of the node
};

// AVL class to represent the AVL tree
class AVL
{
public:
    Node *root; // Root of the AVL tree

    AVL() { root = nullptr; } // Constructor to initialize the root

    // Helper methods for inserting
    int NodeHeight(Node *p);    // Calculate the height of a node
    int BalanceFactor(Node *p); // Calculate the balance factor of a node
    Node *LLRotation(Node *p);  // Perform LL rotation
    Node *RRRotation(Node *p);  // Perform RR rotation
    Node *LRRotation(Node *p);  // Perform LR rotation
    Node *RLRotation(Node *p);  // Perform RL rotation

    // Insert a new node into the AVL tree
    Node *rInsert(Node *p, int key);

    // Perform an inorder traversal of the AVL tree
    void Inorder(Node *p);
    void Inorder() { Inorder(root); } // Inorder traversal of the root
    Node *getRoot() { return root; }  // Get the root of the AVL tree
};

// Calculate the height of a node
int AVL::NodeHeight(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

// Calculate the balance factor of a node
int AVL::BalanceFactor(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

// Perform LL rotation
Node *AVL::LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root
    if (root == p)
    {
        root = pl;
    }
    return pl;
}

// Perform RR rotation
Node *AVL::RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root
    if (root == p)
    {
        root = pr;
    }
    return pr;
}

// Perform LR rotation
Node *AVL::LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    // Update height
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    // Update root
    if (p == root)
    {
        root = plr;
    }
    return plr;
}

// Perform RL rotation
Node *AVL::RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root
    if (root == p)
    {
        root = prl;
    }
    return prl;
}

// Insert a new node into the AVL tree
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
        p->lchild = rInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rInsert(p->rchild, key);
    }

    // Update height
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

    return p;
}

// Perform an inorder traversal of the AVL tree
void AVL::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

int main()
{
    // LR Rotation
    AVL tlr;
    tlr.root = tlr.rInsert(tlr.root, 50);
    tlr.root = tlr.rInsert(tlr.root, 10);
    tlr.root = tlr.rInsert(tlr.root, 20);

    tlr.Inorder();
    cout << endl;
    cout << tlr.root->data << endl;

    // RL Rotation
    AVL trl;
    trl.root = trl.rInsert(trl.root, 20);
    trl.root = trl.rInsert(trl.root, 50);
    trl.root = trl.rInsert(trl.root, 30);

    trl.Inorder();
    cout << endl;
    cout << trl.root->data << endl;

    return 0;
}