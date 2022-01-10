//Find Lowest Common Ancestor(LCA) in a BST
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
Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (n1 < root->data && n2 < root->data)
        LCA(root->left, n1, n2);
    else if (n1 > root->data && n2 > root->data)
        LCA(root->right, n1, n2);
    else
        return root;
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
    int n1, n2;
    cout << "\nEnter the two nodes: " << endl;
    cin >> n1 >> n2;
    Node *res = LCA(root, n1, n2);
    cout << "The Lowest Common Ancestor is: " << res->data << endl;
    return 0;
}
