// Check whether a given tree is a BST or not
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
// Time->O(n)
// Space->O(1)
// Approach-I
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
// Time->O(n)
// Space->O(1)
// Approach-II
bool checkBST(Node *root, int minRange, int maxRange)
{
    if (root == NULL)
        return true;
    if (root->data <= minRange || root->data >= maxRange)
        return false;
    return checkBST(root->left, INT_MIN, root->data) && checkBST(root->right, root->data, INT_MAX);
}
bool isBST(Node *root)
{
    return checkBST(root, INT_MIN, INT_MAX);
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 5);
    insert(root, 4);
    insert(root, 8);
    insert(root, 3);
    insert(root, 6);
    insert(root, 7);
    cout << "Inorder Traversal of BST is: " << endl;
    Inorder(root);
    if (isBST(root))
        cout << "\nThe given tree is a BST" << endl;
    else
        cout << "\nNot a BST" << endl;
    return 0;
}
