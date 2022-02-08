// Count Complete Tree Nodes(Leetcode Q222)
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
int findLeftHeight(node *node)
{
    int lh = 0;
    while (node)
    {
        lh++;
        node = node->lchild;
    }
    return lh;
}
int findRightHeight(node *node)
{
    int rh = 0;
    while (node)
    {
        rh++;
        node = node->rchild;
    }
    return rh;
}
// Time->O(log^2n)
// Space->O(height)
int countNodes(node *root)
{
    if (root == NULL)
        return 0;
    int left = findLeftHeight(root);
    int right = findRightHeight(root);

    if (left == right)
        return (1 << left) - 1;
    return 1 + countNodes(root->lchild) + countNodes(root->rchild);
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "Binary Tree is: " << endl;
    inorderTraversal(root);
    cout << endl;
    cout << "Number of complete tree nodes is: " << countNodes(root) << endl;
    return 0;
}