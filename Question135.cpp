//Find largest SubTree sum of a Binary Tree
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
int ma = 0;
int SubTreeSum(struct node *root)
{
    if (root == NULL)
        return 0;
    int left = SubTreeSum(root->lchild);
    int right = SubTreeSum(root->rchild);
    ma = max(ma, left + right + root->data);
    return left + right + root->data;
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
    cout << "\nLargest SubTree Sum is: " << SubTreeSum(root);
    return 0;
}
