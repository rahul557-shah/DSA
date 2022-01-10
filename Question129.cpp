//Check if a binary tree contains duplicate subtrees of size more than 2
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
string Check(struct node *root, unordered_map<string, int> &m)
{
    if (root == NULL)
        return "$";
    string s = "";
    if (root->lchild == NULL && root->rchild == NULL)
    {
        s = to_string(root->data);
        return s;
    }
    s = s + to_string(root->data);
    s = s + Check(root->lchild, m);
    s = s + Check(root->rchild, m);
    m[s]++;
    return s;
}
bool CheckLeafNodes(struct node *root)
{
    unordered_map<string, int> m;
    Check(root, m);
    for (auto x : m)
    {
        if (x.second >= 2)
            return true;
    }
    return false;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "The Inorder Traversal of the Binary tree is: " << endl;
    Inorder(root);
    cout << endl;
    if (CheckLeafNodes(root))
        cout << "Yes Binary tree has duplicate subtrees" << endl;
    else
        cout << "No Duplicate Subtrees" << endl;
    return 0;
}
