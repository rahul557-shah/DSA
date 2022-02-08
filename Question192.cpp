// Path Sum(Leetcode Q.112)
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
bool pathSum(node *root, int k)
{
    if (root == NULL)
        return false;
    int sum = k - root->data;
    if (sum == 0 && root->lchild == NULL && root->rchild == NULL)
        return true;
    bool left = pathSum(root->lchild, sum);
    bool right = pathSum(root->rchild, sum);
    return left || right;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "Binary Tree is: " << endl;
    inorderTraversal(root);
    cout << endl;
    int k;
    cout << "Enter the target:" << endl;
    cin >> k;
    if (pathSum(root, k))
        cout << "Path Sum is present!!" << endl;
    else
        cout << "Not Present!!" << endl;
    return 0;
}