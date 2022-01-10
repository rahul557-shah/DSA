//Check whether the given Binary Tree is a Sum tree or not
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
int Check(struct node *root, int &flag)
{
    if (root == NULL)
        return 0;
    if (root->lchild == NULL && root->rchild == NULL)
        return root->data;
    if (flag == 0)
        return 0;
    int x = Check(root->lchild, flag);
    int y = Check(root->rchild, flag);
    if (x + y != root->data)
        flag = 0;
    return x + y + root->data;
}
bool IsSumTree(struct node *root)
{
    int flag = 1;
    Check(root, flag);
    return flag;
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
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "The Inorder Traversal of the Binary tree is: " << endl;
    Inorder(root);
    cout << endl;
    if (IsSumTree(root))
        cout << "Yes it is a sum tree" << endl;
    else
        cout << "Not a sum tree" << endl;
    return 0;
}
