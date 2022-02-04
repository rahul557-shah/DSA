// Flatten a Binary Tree into a Linked List(Leetcode Q.114)
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
// Time->O(n)
// Space->O(n)
void Flatten(struct node *root)
{
    stack<node *> st;
    if (root == NULL)
        return;
    st.push(root);
    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();
        if (temp->rchild != NULL)
            st.push(temp->rchild);
        if (temp->lchild != NULL)
            st.push(temp->lchild);
        if (!st.empty())
            temp->rchild = st.top();
        temp->lchild = NULL;
    }
}
// Time->O(n)
// Space->O(1)
node *FlattenInConstantSpace(struct node *root)
{
    node *curr = root, *prev;
    while (curr != NULL)
    {
        if (curr->lchild)
        {
            prev = curr->lchild;
            while (prev->rchild)
                prev = prev->rchild;
            prev->rchild = curr->rchild;
            curr->rchild = curr->lchild;
            curr->lchild = NULL;
        }
        curr = curr->rchild;
    }
    return root;
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
    int n1, n2;
    cout << "Create a binary tree" << endl;
    Treecreate();
    node *res = FlattenInConstantSpace(root);
    cout << "Flattened Linked List" << endl;
    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->rchild;
    }
    cout << endl;
    return 0;
}
