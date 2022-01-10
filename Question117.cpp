//Zigzag Traversal of a Binary Tree
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
vector<int> ZigZagTraversal(struct node *root)
{
    vector<int> res;
    queue<node *> q;
    if (root == NULL)
        return res;
    q.push(root);
    int flag = 1;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        while (size != 0)
        {
            node *t = q.front();
            temp.push_back(t->data);
            if (t->lchild)
                q.push(t->lchild);
            if (t->rchild)
                q.push(t->rchild);
            q.pop();
            size--;
        }
        if (flag % 2 == 0)
            reverse(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++)
            res.push_back(temp[i]);
        flag = !flag;
    }
    return res;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    vector<int> result;
    result = ZigZagTraversal(root);
    cout << "ZigZag Traversal of binary tree is \n";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}
