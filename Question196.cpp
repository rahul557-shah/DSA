// Two Sums-IV(Leetcode Q653)
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
void inorderTraversal(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}
// Time->O(n)
// Space->O(n)
bool twoSum(Node *root, int k)
{
    if (root == NULL)
        return false;
    vector<int> ans;
    inorderTraversal(root, ans);
    int low = 0, high = ans.size() - 1;
    while (low < high)
    {
        if (ans[low] + ans[high] == k)
            return true;
        else if (ans[low] + ans[high] > k)
            high--;
        else
            low++;
    }
    return false;
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 7);
    cout << "Inorder Traversal of BST is: " << endl;
    Inorder(root);
    int K;
    cout << "\nEnter the value of target" << endl;
    cin >> K;
    if (twoSum(root, K))
        cout << "Target Found!!" << endl;
    else
        cout << "Not Found!!" << endl;
    return 0;
}