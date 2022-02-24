// Floor and Ceil in a BST(Coding Ninjas)
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
void Inorder(Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}
// Time->O(logn)
// Space->O(1)
int floorInABst(Node *root, int K)
{
    int floor = -1;
    while (root != NULL)
    {
        if (K == root->data)
        {
            floor = root->data;
            return floor;
        }
        if (K < root->data)
            root = root->left;
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}
// Time->O(logn)
// Space->O(1)
int ceilInABst(Node *root, int K)
{
    int ceil = -1;
    while (root != NULL)
    {
        if (K == root->data)
        {
            ceil = root->data;
            return ceil;
        }
        if (K < root->data)
        {
            ceil = root->data;
            root = root->left;
        }
        else
            root = root->right;
    }
    return ceil;
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 10);
    insert(root, 15);
    insert(root, 13);
    insert(root, 3);
    insert(root, 6);
    insert(root, 11);
    insert(root, 14);
    insert(root, 2);
    insert(root, 4);
    insert(root, 9);
    cout << "Inorder Traversal of BST is: " << endl;
    Inorder(root);
    int K;
    cout << "\nEnter the value of K" << endl;
    cin >> K;
    cout << "Floor in a BST is: " << floorInABst(root, K) << endl;
    cout << "Ceil in a BST is: " << ceilInABst(root, K) << endl;
    return 0;
}