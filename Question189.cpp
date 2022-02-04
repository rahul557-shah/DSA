// Maximum Path Sum of a Binary Tree(Leetcode Q.124)
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
// Time->O(n)
// Space->O(height)
int MaxSum(node *node, int &maxi)
{
    if (root == NULL)
        return 0;
    int left = max(0, MaxSum(node->lchild, maxi));
    int right = max(0, MaxSum(node->rchild, maxi));

    maxi = max(maxi, node->data + left + right);

    return node->data + max(left, right);
}
int findMaxPathSum(node *root)
{
    int maxi = INT_MIN;
    MaxSum(root, maxi);
    return maxi;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "Binary Tree is: " << endl;
    inorderTraversal(root);
    cout << endl;
    cout << "Maximum Path Sum is: " << findMaxPathSum(root) << endl;
    return 0;
}