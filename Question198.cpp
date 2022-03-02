// Recover Binary Search Tree(Leetcode Q.99)
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
void inorderTraversal(node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->lchild);
    cout << root->data << " ";
    inorderTraversal(root->rchild);
}
void inorderRecover(node *root, node *&first, node *&mid, node *&last, node *&prev)
{
    if (root == NULL)
        return;
    inorderRecover(root->lchild, first, mid, last, prev);
    if (prev != NULL && prev->data > root->data)
    {
        if (first == NULL)
        {
            first = prev;
            mid = root;
        }
        else
            last = root;
    }
    prev = root;
    inorderRecover(root->rchild, first, mid, last, prev);
}
// Time->O(n)
// Space->O(height)
node *recoverBST(node *root)
{
    node *first = NULL, *mid = NULL, *last = NULL;
    node *prev = (struct node *)malloc(sizeof(struct node));
    prev->data = INT_MIN;
    inorderRecover(root, first, mid, last, prev);
    if (first && last)
        swap(first->data, last->data);
    else if (first && mid)
        swap(first->data, mid->data);
    return root;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "Binary Search Tree with errors is: " << endl;
    inorderTraversal(root);
    cout << endl;
    node *res = recoverBST(root);
    cout << "Recovered BST is: " << endl;
    inorderTraversal(res);
    return 0;
}