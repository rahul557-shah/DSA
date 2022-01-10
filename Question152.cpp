//Check whether a BST contains dead end or not
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
    else if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
void Preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}
bool Check(Node *root, int min, int max)
{
    if (root == NULL)
        return false;
    if (min == max)
        return true;
    bool x = Check(root->left, min, root->data - 1);
    bool y = Check(root->right, root->data + 1, max);
    return x || y;
}
//Time->O(n)
//Space->O(1)
bool DeadEnd(Node *root)
{
    return Check(root, 1, INT_MAX);
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 8);
    insert(root, 7);
    insert(root, 10);
    insert(root, 2);
    insert(root, 9);
    insert(root, 13);
    cout << "Preorder Traversal of Normal BST is: " << endl;
    Preorder(root);
    if (DeadEnd(root))
        cout << "\nYes there is a dead end" << endl;
    else
        cout << "\nNo dead end" << endl;
    return 0;
}
