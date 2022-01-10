//Find all the duplicate sub trees of a Binary Tree
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
string Check(struct node *root, unordered_map<string, int> &m, vector<node *> &res)
{
    if (root == NULL)
        return "";
    string str = "(";
    str += Check(root->lchild, m, res);
    str += to_string(root->data);
    str += Check(root->rchild, m, res);
    str += ")";
    if (m[str] == 1)
        res.push_back(root);
    m[str]++;
    return str;
}
vector<node *> AllDuplicates(struct node *root)
{
    vector<node *> res;
    unordered_map<string, int> m;
    Check(root, m, res);
    return res;
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
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "PreOrder Traversal is: " << endl;
    PreOrder(root);
    cout << "\nAll the Duplicate Subtrees are: " << endl;
    vector<node *> result = AllDuplicates(root);
    for (int i = 0; i < result.size(); i++)
    {
        PreOrder(result[i]);
        cout << endl;
    }
    cout << endl;
    return 0;
}
