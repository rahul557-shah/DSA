//Convert a Normal BST to a Balanced BST
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
void InorderAdd(Node *root, vector<Node *> &res)
{
    if (root != NULL)
    {
        InorderAdd(root->left, res);
        res.push_back(root);
        InorderAdd(root->right, res);
    }
}
Node *Check(vector<Node *> &res, int l, int h)
{
    if (l > h)
        return NULL;
    int mid = (l + h) / 2;
    Node *root1 = res[mid];
    root1->left = Check(res, l, mid - 1);
    root1->right = Check(res, mid + 1, h);
    return root1;
}
Node *BalancedBST(Node *root)
{
    vector<Node *> res;
    InorderAdd(root, res);
    int n = res.size();
    return Check(res, 0, n - 1);
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
    cout << "Preorder Traversal of Normal BST is: " << endl;
    Preorder(root);
    Node *result = BalancedBST(root);
    cout << "\nPreorder Traversal of Balanced BST is: " << endl;
    Preorder(result);
    return 0;
}
