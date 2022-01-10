//Find Sum of nodes on the longest path from root to leaf
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
vector<int> FindLongestSum(struct node *root)
{
    if (root == NULL)
        return {0, 0};
    vector<int> a = FindLongestSum(root->lchild);
    vector<int> b = FindLongestSum(root->rchild);
    if (a[0] > b[0])
        return {a[0] + 1, a[1] + root->data};
    else if (a[0] < b[0])
        return {b[0] + 1, b[1] + root->data};
    else
        return {a[0] + 1, max(a[1], b[1]) + root->data};
}
int LongestBloodline(struct node *root)
{
    vector<int> res;
    res = FindLongestSum(root);
    return res[1];
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "The Inorder Traversal of the Binary tree is: " << endl;
    Inorder(root);
    cout << "\nSum of longest BloodLine is: " << LongestBloodline(root) << endl;
    return 0;
}
