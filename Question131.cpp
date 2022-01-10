//Find the Lowest Common Ancestor(LCA) of a binary tree
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
node *FindLCA(struct node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    node *l = FindLCA(root->lchild, n1, n2);
    node *r = FindLCA(root->rchild, n1, n2);
    if (l != NULL && r != NULL)
        return root;
    else if (l != NULL)
        return l;
    else
        return r;
}
int main()
{
    int n1, n2;
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "The Inorder Traversal of the Binary tree is: " << endl;
    Inorder(root);
    cout << "\nEnter the value of n1:" << endl;
    cin >> n1;
    cout << "Enter the value of n2:" << endl;
    cin >> n2;
    node *res = FindLCA(root, n1, n2);
    cout << "The Lowest Common Ancestor is: " << res->data << endl;
    return 0;
}
