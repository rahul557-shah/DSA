//Diagonal Traversal of Binary Tree
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
vector<int> DiagonalTraversal(struct node *root)
{
    vector<int> res;
    queue<node *> q;
    if (root == NULL)
        return res;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        while (temp != NULL)
        {
            if (temp->lchild != NULL)
                q.push(temp->lchild);
            res.push_back(temp->data);
            temp = temp->rchild;
        }
    }
    return res;
}
int main()
{
    int n1, n2;
    cout << "Create a binary tree" << endl;
    Treecreate();
    vector<int> result;
    result = DiagonalTraversal(root);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}
