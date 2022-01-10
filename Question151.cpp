//Count pairs from 2 BSTs whose sum is equal to x
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
bool Search(Node *root2, int k)
{
    bool x = false;
    bool y = false;
    if (root2 == NULL)
        return false;
    if (k == root2->data)
        return true;
    else if (k < root2->data)
        x = Search(root2->left, k);
    else
        y = Search(root2->right, k);
    return x || y;
}
void InorderCalc(Node *root1, Node *root2, int x, int &c)
{
    if (root1 == NULL)
        return;
    InorderCalc(root1->left, root2, x, c);
    if (Search(root2, x - root1->data))
        c++;
    InorderCalc(root1->right, root2, x, c);
}
int CountSum(Node *root1, Node *root2, int x)
{
    int c = 0;
    InorderCalc(root1, root2, x, c);
    return c;
}
int main()
{
    struct Node *root1 = NULL, *root2 = NULL;
    root1 = insert(root1, 15);
    insert(root1, 10);
    insert(root1, 5);
    insert(root1, 12);
    insert(root1, 17);
    insert(root1, 18);
    root2 = insert(root2, 10);
    insert(root2, 15);
    insert(root2, 22);
    cout << "Preorder Traversal of First BST is: " << endl;
    Preorder(root1);
    cout << "\nPreorder Traversal of Second BST is: " << endl;
    Preorder(root2);
    int x;
    cout << "\nEnter the sum : " << endl;
    cin >> x;
    cout << "Number of sum from both BSTs are :" << CountSum(root1, root2, x) << endl;
    return 0;
}
