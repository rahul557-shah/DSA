//Reverse Level Order Traversal Of a Binary Tree
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
//Time->O(n)
//Space->O(n)
vector<int> ReverseLevelOrder(struct node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        res.push_back(temp->data);
        if (temp->rchild)
            q.push(temp->rchild);
        if (temp->lchild)
            q.push(temp->lchild);
        q.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    vector<int> result;
    result = ReverseLevelOrder(root);
    cout << "Level Order traversal of binary tree is \n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
