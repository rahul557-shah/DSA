//Boundary Traversal of a Binary Tree
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
void LeftBoundary(struct node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    if (root->lchild)
    {
        res.push_back(root->data);
        LeftBoundary(root->lchild, res);
    }
    else if (root->rchild)
    {
        res.push_back(root->data);
        LeftBoundary(root->rchild, res);
    }
}
void LeafNodes(struct node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    LeafNodes(root->lchild, res);
    if (root->lchild == NULL && root->rchild == NULL)
        res.push_back(root->data);
    LeafNodes(root->rchild, res);
}
void RightBoundary(struct node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    if (root->rchild)
    {
        RightBoundary(root->rchild, res);
        res.push_back(root->data);
    }
    else if (root->lchild)
    {
        RightBoundary(root->lchild, res);
        res.push_back(root->data);
    }
}
vector<int> BoundaryTraversal(struct node *root)
{
    vector<int> res;
    res.push_back(root->data);
    LeftBoundary(root->lchild, res);
    LeafNodes(root, res);
    RightBoundary(root->rchild, res);
    return res;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    vector<int> result;
    cout << "Boundary Traversal of a Binary Tree is: " << endl;
    result = BoundaryTraversal(root);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}
