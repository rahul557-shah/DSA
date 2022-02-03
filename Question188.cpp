// Symmetric Binary Tree(Leetcode Q.101)
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
bool isMirror(node *r1, node *r2)
{
    if (r1 == NULL || r2 == NULL)
        return r1 == r2;
    if (r1->data != r2->data)
        return false;
    return isMirror(r1->lchild, r2->rchild) && isMirror(r1->rchild, r2->lchild);
}
bool isSymmetry(node *root)
{
    return isMirror(root, root);
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "Binary Tree is: " << endl;
    inorderTraversal(root);
    cout << endl;
    if (isSymmetry(root))
        cout << "Symmetric Binary Tree!!" << endl;
    else
        cout << "Not a Symmetric Binary Tree" << endl;
    return 0;
}
