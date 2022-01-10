//Find Kth Smallest element in a BST
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
void Check(Node *root, int K, int &count, int &ans)
{
    if (root == NULL)
        return;
    Check(root->left, K, count, ans);
    if (K == count)
    {
        ans = root->data;
        count++;
        return;
    }
    else
        count++;
    Check(root->right, K, count, ans);
}
int KthSmallest(Node *root, int K)
{
    int count = 1;
    int ans = -1;
    Check(root, K, count, ans);
    return ans;
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
    int K;
    cout << "\nEnter the value of K" << endl;
    cin >> K;
    cout << "The " << K << "th Smallest value is: " << KthSmallest(root, K) << endl;
    return 0;
}
