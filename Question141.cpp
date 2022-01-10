//Inorder Predecessor and Inorder Successor of the given node in a BST
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *insert(Node *root, int data)
{
    Node *t;
    if (root == NULL)
    {
        t = new Node();
        t->data = data;
        t->left = t->right = NULL;
        return t;
    }
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
void Inorder(Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}
Node *InorderPre(Node *root)
{
    Node *p = root->left;
    if (p != NULL && p->right != NULL)
        p = p->right;
    return p;
}
Node *InorderSucc(Node *root)
{
    Node *p = root->right;
    if (p != NULL && p->left != NULL)
        p = p->left;
    return p;
}
void FindPreSuc(Node *root, Node *&pre, Node *&succ, int key)
{
    if (root == NULL)
        return;
    if (root->data == key)
    {
        if (root->left != NULL)
            pre = InorderPre(root);
        if (root->right != NULL)
            succ = InorderSucc(root);
        return;
    }
    else if (root->data < key)
    {
        pre = root;
        FindPreSuc(root->right, pre, succ, key);
    }
    else
    {
        succ = root;
        FindPreSuc(root->left, pre, succ, key);
    }
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 15);
    insert(root, 10);
    insert(root, 18);
    insert(root, 25);
    insert(root, 7);
    insert(root, 1);
    cout << "Inorder Traversal of BST is: " << endl;
    Inorder(root);
    int key;
    Node *pre = NULL, *succ = NULL;
    cout << "\nEnter the key" << endl;
    cin >> key;
    cout << "The Predecessor and Successor of the key is: " << endl;
    FindPreSuc(root, pre, succ, key);
    if (pre != NULL)
        cout << pre->data << endl;
    else
        cout << "NULL" << endl;
    if (succ != NULL)
        cout << succ->data;
    else
        cout << "NULL" << endl;
    return 0;
}
