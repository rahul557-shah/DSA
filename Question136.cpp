//Maximum Sum of Non-Adjacent Nodes
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
unordered_map<node *, int> mymap;
int MaxSum(struct node *root)
{
    if (root == NULL)
        return 0;
    if (mymap[root])
        return mymap[root];
    int inc = root->data;
    if (root->lchild)
    {
        inc += MaxSum(root->lchild->lchild);
        inc += MaxSum(root->lchild->rchild);
    }
    if (root->rchild)
    {
        inc += MaxSum(root->rchild->lchild);
        inc += MaxSum(root->rchild->rchild);
    }
    int exc = MaxSum(root->lchild) + MaxSum(root->rchild);
    mymap[root] = max(inc, exc);
    return mymap[root];
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
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "PreOrder Traversal is: " << endl;
    PreOrder(root);
    cout << "\nMaximum Sum of Non Adjacent Nodes is: " << MaxSum(root);
    return 0;
}
