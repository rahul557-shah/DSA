//Tree Traversals(Both Recursive and Iterative)
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
void RecurPreOrder(struct node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        RecurPreOrder(p->lchild);
        RecurPreOrder(p->rchild);
    }
}
void IterativePreOrder(struct node *p)
{
    stack<node *> st;
    while (p != NULL || !st.empty())
    {
        if (p != NULL)
        {
            cout << p->data << " ";
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.top();
            p = p->rchild;
            st.pop();
        }
    }
}
void RecurInOrder(struct node *p)
{
    if (p != NULL)
    {
        RecurInOrder(p->lchild);
        cout << p->data << " ";
        RecurInOrder(p->rchild);
    }
}
void IterativeInOrder(struct node *p)
{
    stack<node *> st;
    while (p != NULL || !st.empty())
    {
        if (p != NULL)
        {
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.top();
            cout << p->data << " ";
            p = p->rchild;
            st.pop();
        }
    }
}
void RecurPostOrder(struct node *p)
{
    if (p != NULL)
    {
        RecurPostOrder(p->lchild);
        RecurPostOrder(p->rchild);
        cout << p->data << " ";
    }
}
//Using two stacks
void IterativePostOrder(struct node *p)
{
    if (p == NULL)
        return;
    stack<node *> st1;
    stack<node *> st2;
    st1.push(p);
    node *temp;
    while (!st1.empty())
    {
        temp = st1.top();
        st1.pop();
        st2.push(temp);
        if (temp->lchild)
            st1.push(temp->lchild);
        if (temp->rchild)
            st1.push(temp->rchild);
    }
    while (!st2.empty())
    {
        temp = st2.top();
        st2.pop();
        cout << temp->data << " ";
    }
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "PreOrder Traversal: " << endl;
    IterativePreOrder(root);
    cout << "\nInorder Traversal: " << endl;
    IterativeInOrder(root);
    cout << "\nPostOrder Traversal: " << endl;
    IterativePostOrder(root);
    return 0;
}
