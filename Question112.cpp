//Height of Binary Tree
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
vector<int> LevelOrder(struct node *root)
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
        if (temp->lchild)
            q.push(temp->lchild);
        if (temp->rchild)
            q.push(temp->rchild);
        q.pop();
    }
    return res;
}
//Time->O(n)
//Space->O(n)[With Stack Frame]
int height(struct node *root)
{
    if (root != NULL)
    {
        int x = height(root->lchild);
        int y = height(root->rchild);
        return 1 + max(x, y);
    }
    return 0;
}
int main()
{
    cout << "Create a binary tree " << endl;
    Treecreate();
    cout << "Level Order Traversal: " << endl;
    vector<int> result;
    result = LevelOrder(root);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << "\nHeight of the Binary Tree : " << height(root) << endl;
    return 0;
}