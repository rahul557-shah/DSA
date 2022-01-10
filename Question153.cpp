//Largest BST in a Binary Tree
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
void PreOrder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}
vector<int> Check(node *root)
{
    if (root == NULL)
        return {1, 0, INT_MAX, INT_MIN};
    if (root->lchild == NULL && root->rchild == NULL)
        return {1, 1, root->data, root->data};
    vector<int> l = Check(root->lchild);
    vector<int> r = Check(root->rchild);
    if (l[0] == 1 && r[0] == 1)
    {
        if (root->data > l[3] && root->data < r[2])
        {
            int x = l[2];
            int y = r[3];
            if (x == INT_MAX)
                x = root->data;
            if (y == INT_MIN)
                y = root->data;
            return {1, l[1] + r[1] + 1, x, y};
        }
    }
    return {0, max(l[1], r[1]), 0, 0};
}
int largestBst(node *root)
{
    vector<int> res = Check(root);
    return res[1];
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "PreOrder Traversal is: " << endl;
    PreOrder(root);
    cout << "\nSize of Largest BST is: " << largestBst(root) << endl;
    return 0;
}
