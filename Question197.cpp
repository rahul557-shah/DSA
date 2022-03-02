// Convert a sorted array to a BST(Leetcode Q.108)
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
        cout << A[i] << " ";
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
// Time->O(n)
// Space->O(n)
Node *convertToBST(int A[], int low, int high)
{
    if (low > high)
        return NULL;
    int mid = (low + high) / 2;
    Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = A[mid];
    root->left = convertToBST(A, low, mid - 1);
    root->right = convertToBST(A, mid + 1, high);
    return root;
}
int main()
{
    int n;
    cout << "Enter the size:" << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "Sorted Array is: " << endl;
    printArray(A, n);
    Node *root = convertToBST(A, 0, n - 1);
    cout << "Inorder Traversal is:" << endl;
    inorderTraversal(root);
    return 0;
}