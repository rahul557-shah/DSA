//Convert a Binary Tree into a BST
#include <bits/stdc++.h>
using namespace std;
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL;
void Treecreate()
{
    int x;
    struct node *p, *t;
    queue<node *> q;
    root = new node();
    printf("Enter the root: ");
    scanf("%d", &x);
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node();
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node();
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
        q.pop();
    }
}
void Inorder_Tree(node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    Inorder_Tree(root->lchild, res);
    res.push_back(root->data);
    Inorder_Tree(root->rchild, res);
}
void Inorder_BST(node *root, vector<int> &res, int &i)
{
    if (root == NULL)
        return;
    Inorder_BST(root->lchild, res, i);
    root->data = res[i];
    i++;
    Inorder_BST(root->rchild, res, i);
}
node *ConvertToBST(node *root)
{
    vector<int> res;
    Inorder_Tree(root, res);
    sort(res.begin(), res.end());
    int i = 0;
    Inorder_BST(root, res, i);
    return root;
}
void printInorder(node *root)
{
    if (root == NULL)
        return;
    printInorder(root->lchild);
    cout << root->data << " ";
    printInorder(root->rchild);
}
int main()
{
    int a, b;
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "InOrder Traversal of Binary Tree is: " << endl;
    printInorder(root);
    node *result = ConvertToBST(root);
    cout << "\nInOrder Traversal of BST is: " << endl;
    printInorder(result);
    return 0;
}
