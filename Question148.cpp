//Median of nodes in a BST
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
void InorderVector(Node *root, vector<int> &res)
{
    if (root != NULL)
    {
        InorderVector(root->left, res);
        res.push_back(root->data);
        InorderVector(root->right, res);
    }
}
//Time->O(n)
//Space->O(n)
float Median(Node *root)
{
    vector<int> res;
    InorderVector(root, res);
    int n = res.size();
    if (n % 2 == 0)
        return (res[(n - 1) / 2] + res[n / 2]) / 2.0;
    else
        return res[n / 2];
}
void CountNodes(Node *root, int &count)
{
    if (root == NULL)
        return;
    CountNodes(root->left, count);
    count++;
    CountNodes(root->right, count);
}
void Calculate(Node *root, Node *&prev, Node *&curr, int &flag, int &k, int n)
{
    if (root == NULL)
        return;
    Calculate(root->left, prev, curr, flag, k, n);
    if (prev == NULL)
    {
        prev = root;
        k++;
    }
    else if (k == n)
    {
        k++;
        curr = root;
        flag = 1;
        return;
    }
    else if (flag == 0)
    {
        k++;
        prev = root;
    }
    Calculate(root->right, prev, curr, flag, k, n);
}
//Time->O(n)
//Space->O(1)
float MedianOfNodes(Node *root)
{
    Node *curr = NULL, *prev = NULL;
    int count = 0;
    CountNodes(root, count);
    int n = (count / 2) + 1;
    int flag = 0;
    int k = 1;
    Calculate(root, prev, curr, flag, k, n);
    if (count % 2 == 1)
        return curr->data * 1.0;
    else
        return ((curr->data + prev->data) / 2.0);
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
    //insert(root, 16);
    cout << "Inorder Traversal is: " << endl;
    Inorder(root);
    cout << "\nMedian of nodes of the BST is: " << MedianOfNodes(root) << endl;
    return 0;
}
