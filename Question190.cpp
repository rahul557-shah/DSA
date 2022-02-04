// Maximum Width of a Binary Tree(Leetcode Q.662)
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
void inorderTraversal(node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->lchild);
    cout << root->data << " ";
    inorderTraversal(root->rchild);
}
// Time->O(n)
// Space->O(n)
int findMaxWidth(node *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int mini = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            long long curr = q.front().second - mini;
            node *node = q.front().first;
            q.pop();
            if (i == 0)
                first = curr;
            if (i == size - 1)
                last = curr;
            if (node->lchild)
                q.push({node->lchild, 2 * curr + 1});
            if (node->rchild)
                q.push({node->rchild, 2 * curr + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "Binary Tree is: " << endl;
    inorderTraversal(root);
    cout << endl;
    cout << "Maximum Width of the Binary Tree is: " << findMaxWidth(root) << endl;
    return 0;
}