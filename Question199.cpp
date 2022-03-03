// Merge Two BSTs into a sorted array(GFG)
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
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
void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
vector<int> mergeBoth(vector<int> &v1, vector<int> &v2, vector<int> &res)
{
    int m = v1.size();
    int n = v2.size();
    int i = 0, j = 0;
    if (m == 0)
        return v2;
    else if (n == 0)
        return v1;
    else
    {
        while (i < m && j < n)
        {
            if (v1[i] <= v2[j])
                res.push_back(v1[i++]);
            else
                res.push_back(v2[j++]);
        }
    }
    while (i < m)
        res.push_back(v1[i++]);
    while (j < n)
        res.push_back(v2[j++]);
    return res;
}
// Time->O(m+n)
// Space->O(m+n)
vector<int> mergeBST(Node *root1, Node *root2)
{
    vector<int> v1, v2, res;
    inorder(root1, v1);
    inorder(root2, v2);
    return mergeBoth(v1, v2, res);
}
int main()
{
    struct Node *root1 = NULL, *root2 = NULL;
    root1 = insert(root1, 5);
    insert(root1, 6);
    insert(root1, 3);
    insert(root1, 2);
    insert(root1, 4);
    cout << "Preorder Traversal of first BST is: " << endl;
    Preorder(root1);
    cout << endl;
    root2 = insert(root2, 2);
    insert(root2, 3);
    insert(root2, 1);
    insert(root2, 6);
    insert(root2, 7);
    cout << "Preorder Traversal of second BST is: " << endl;
    Preorder(root2);
    cout << "\nMerged BST is: " << endl;
    vector<int> ans = mergeBST(root1, root2);
    printArray(ans);
    return 0;
}
