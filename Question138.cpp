//Minimum distance between two nodes in a Binary Tree
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
void PreOrder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}
node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    node *left = lca(root->lchild, n1, n2);
    node *right = lca(root->rchild, n1, n2);
    if (left != NULL && right != NULL)
        return root;
    else if (left != NULL)
        return left;
    else
        return right;
}
int Find(node *root, int val)
{
    if (root == NULL)
        return 0;
    if (root->data == val)
        return 1;
    int a = Find(root->lchild, val);
    int b = Find(root->rchild, val);
    if (a == 0 && b == 0)
        return 0;
    else
        return a + b + 1;
}
int MinDistance(node *root, int a, int b)
{
    node *LCA = lca(root, a, b);
    int x = Find(LCA, a);
    int y = Find(LCA, b);
    return x + y - 2;
}
int main()
{
    int a, b;
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "PreOrder Traversal is: " << endl;
    PreOrder(root);
    cout << "\nEnter the first node: " << endl;
    cin >> a;
    cout << "Enter the second node: " << endl;
    cin >> b;
    cout << "The distance between the nodes is: " << MinDistance(root, a, b) << endl;
    return 0;
}
