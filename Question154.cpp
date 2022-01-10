//Replace every element with the least greater element on its right
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
} *root = NULL;
Node *insert(Node *root, int data, Node *&succ)
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
    {
        succ = root;
        root->left = insert(root->left, data, succ);
    }
    else if (data > root->data)
        root->right = insert(root->right, data, succ);
    return root;
}
void replace(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        Node *succ = NULL;
        root = insert(root, arr[i], succ);
        if (succ)
            arr[i] = succ->data;
        else
            arr[i] = -1;
    }
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    replace(arr, n);
    cout << "The least greater elements are:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
