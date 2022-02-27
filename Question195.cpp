// Construct a BST from preorder traversal(leetcode Q1008)
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
Node *buildBST(int A[], int n, int &i, int bound)
{
    if (i == n || A[i] > bound)
        return NULL;
    Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = A[i++];
    root->left = buildBST(A, n, i, root->data);
    root->right = buildBST(A, n, i, bound);
    return root;
}
// Time->O(n)
// Space->O(1)
Node *constructBST(int A[], int n)
{
    int i = 0;
    return buildBST(A, n, i, INT_MAX);
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "PreOrder is: " << endl;
    printArray(A, n);
    Node *res = constructBST(A, n);
    cout << "Binary Search Tree is: " << endl;
    inorderTraversal(res);
    return 0;
}