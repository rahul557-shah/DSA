//Construct a Binary Tree from Inorder and Postorder Traversals
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

struct Node *Find(int in[], int pre[], int lb, int ub, int &index, unordered_map<int, int> &m)
{
    if (lb > ub)
        return NULL;
    struct Node *res = newNode(pre[index--]);
    if (lb == ub)
        return res;
    int mid = m[res->data];
    res->right = Find(in, pre, mid + 1, ub, index, m);
    res->left = Find(in, pre, lb, mid - 1, index, m);
    return res;
}
struct Node *ConstructTree(int in[], int post[], int n)
{
    int index = n - 1;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[in[i]] = i;
    Node *root = Find(in, post, 0, n - 1, index, m);
    return root;
}

void Inorder(struct Node *node)
{
    if (node != NULL)
    {
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    int in[n];
    int post[n];
    cout << "Enter the data in the inorder : " << endl;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    cout << "Enter the data in the postorder : " << endl;
    for (int i = 0; i < n; i++)
        cin >> post[i];
    Node *root = ConstructTree(in, post, n);
    cout << "Binary Treee in InOrder: " << endl;
    Inorder(root);
    return 0;
}
