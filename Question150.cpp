//Merge two Balanced BSTs into a single Balanced BST
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
void InorderAdd1(Node *root, vector<Node *> &res1)
{
    if (root != NULL)
    {
        InorderAdd1(root->left, res1);
        res1.push_back(root);
        InorderAdd1(root->right, res1);
    }
}
void InorderAdd2(Node *root, vector<Node *> &res2)
{
    if (root != NULL)
    {
        InorderAdd2(root->left, res2);
        res2.push_back(root);
        InorderAdd2(root->right, res2);
    }
}
vector<Node *> Merge(vector<Node *> res1, vector<Node *> res2)
{
    vector<Node *> res3;
    int i, j, k;
    i = j = k = 0;
    while (i < res1.size() && j < res2.size())
    {
        if (res1[i]->data <= res2[j]->data)
        {
            res3[k++] = res1[i++];
        }
        else
        {
            res3[k++] = res2[j++];
        }
    }
    while (i < res1.size())
    {
        res3[k++] = res1[i++];
    }
    while (j < res2.size())
    {
        res3[k++] = res2[j++];
    }
    return res3;
}
Node *FinalBalancedBST(vector<Node *> &res3, int l, int h)
{
    if (l > h)
        return NULL;
    int mid = (l + h) / 2;
    Node *rootf = res3[mid];
    rootf->left = FinalBalancedBST(res3, l, mid - 1);
    rootf->right = FinalBalancedBST(res3, mid + 1, h);
    return rootf;
}
Node *Final(Node *root)
{
    vector<Node *> res1, res2, res3;
    res3 = Merge(res1, res2);
    int n = res3.size();
    return FinalBalancedBST(res3, 0, n - 1);
}
int main()
{
    struct Node *root1 = NULL, *root2 = NULL,*root3=NULL;
    root1 = insert(root1, 15);
    insert(root1, 10);
    insert(root1, 18);
    insert(root1, 25);
    insert(root1, 7);
    insert(root1, 30);
    insert(root1, 45);
    insert(root1, 52);
    insert(root1, 38);
    cout << "Preorder Traversal of First BST is: " << endl;
    Preorder(root1);
    root2 = insert(root2, 25);
    insert(root2, 79);
    insert(root2, 17);
    insert(root2, 14);
    insert(root2, 70);
    insert(root2, 34);
    cout << "\nPreorder Traversal of Second BST is: " << endl;
    Preorder(root2);
    Node *result=Final(root3);
    cout << "\nPreorder Traversal of Balanced BST is: " << endl;
    Preorder(result);
    return 0;
}
