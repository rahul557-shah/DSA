//Transform a Binary Tree into a Sum Tree
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
void Inorder(struct node *root)
{
    if (root != NULL)
    {
        Inorder(root->lchild);
        cout << root->data << " ";
        Inorder(root->rchild);
    }
}
int TransformToSumTree(struct node *root)
{
    if (root == NULL)
        return 0;
    int x = TransformToSumTree(root->lchild);
    int y = TransformToSumTree(root->rchild);
    int a = root->data;
    root->data = x + y;
    return x + y + a;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "Inorder of original Binary Tree is:" << endl;
    Inorder(root);
    TransformToSumTree(root);
    cout << "\nInorder of the transformed Sum Tree is:" << endl;
    Inorder(root);
    return 0;
}
