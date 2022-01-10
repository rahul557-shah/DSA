//Check whether all leaf nodes are at same height
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
void Check(struct node *root, int height, int &ans, int &max)
{
    if (root == NULL)
        return;
    if (ans == 0)
        return;
    if (root->lchild == NULL && root->rchild == NULL)
    {
        if (max == -1)
            max = height;
        else
        {
            if (max != height)
                ans = 0;
        }
        return;
    }
    Check(root->lchild, height + 1, ans, max);
    Check(root->rchild, height + 1, ans, max);
}
bool CheckLeafNodes(struct node *root)
{
    int ans = 1;
    int height = 0;
    int max = -1;
    Check(root, height, ans, max);
    return ans;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "The Inorder Traversal of the Binary tree is: " << endl;
    Inorder(root);
    cout << endl;
    if (CheckLeafNodes(root))
        cout << "Yes all leaf nodes are at same height" << endl;
    else
        cout << "No all leaf nodes are not at same height" << endl;
    return 0;
}
