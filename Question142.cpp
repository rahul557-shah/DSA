//Check whether a given tree is a BST or not
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
void Check(Node *root, Node *&prev, int &flag)
{
    if (root == NULL)
        return;
    Check(root->left, prev, flag);
    if (prev != NULL && root->data <= prev->data)
    {
        flag = 0;
        return;
    }
    prev = root;
    Check(root->right, prev, flag);
}
bool IsBST(Node *root)
{
    int flag = 1;
    Node *prev = NULL;
    Check(root, prev, flag);
    return flag;
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
    if (IsBST(root))
        cout << "\nThe given tree is a BST" << endl;
    else
        cout << "\nNot a BST" << endl;
    return 0;
}
