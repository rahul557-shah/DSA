//Bottom View of a Binary Tree
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
//Time->O(nlogn)
//Space->O(n)
vector<int> BottomView(struct node *root)
{
    map<int, int> m;
    vector<int> res;
    queue<pair<node *, int>> q;
    if (root == NULL)
        return res;
    q.push({root, 0});
    while (!q.empty())
    {
        node *temp = q.front().first;
        int hd = q.front().second; //Horizontal Distance
        m[hd] = temp->data;
        if (temp->lchild)
            q.push({temp->lchild, hd - 1});
        if (temp->rchild)
            q.push({temp->rchild, hd + 1});
        q.pop();
    }
    /*for (auto i = m.begin(); i != m.end(); i++)
        res.push_back(i->second);*/
    for (auto i : m)
        res.push_back(i.second);
    return res;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    vector<int> result;
    result = BottomView(root);
    cout << "TopView of binary tree is \n";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}
