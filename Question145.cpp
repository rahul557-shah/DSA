//Count the BST nodes in a given range
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
int CountNodes(Node *root, int l, int h)
{
    if (root == NULL)
        return 0;
    if (root->data >= l && root->data <= h)
        return 1 + CountNodes(root->left, l, h) + CountNodes(root->right, l, h);
    else if (root->data < l)
        return CountNodes(root->right, l, h);
    else
        return CountNodes(root->left, l, h);
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 15);
    insert(root, 10);
    insert(root, 18);
    insert(root, 25);
    insert(root, 7);
    insert(root, 30);
    insert(root, 45);
    insert(root, 52);
    insert(root, 38);
    cout << "Inorder Traversal of BST is: " << endl;
    Inorder(root);
    int l, h;
    cout << "\nEnter the lower and upper range" << endl;
    cin >> l >> h;
    cout << "Total number of nodes in a given range is: " << CountNodes(root, l, h) << endl;
    return 0;
}
