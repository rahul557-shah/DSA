//Maximum and Minimum Element in a BST
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
int Maximum(Node *root)
{
    if (root->right != NULL)
        return Maximum(root->right);
    return root->data;
}
int Minimum(Node *root)
{
    if (root->left != NULL)
        return Minimum(root->left);
    return root->data;
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
    cout << "\nMaximum Element is: " << Maximum(root) << endl;
    cout << "Minimum Element is: " << Minimum(root) << endl;
    return 0;
}
