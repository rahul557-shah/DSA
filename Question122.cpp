//Convert a Binary Tree to a Doubly Linked List
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
void Find(struct node *root, struct node *&head, struct node *&prev, int &flag)
{
    if (root == NULL)
        return;
    Find(root->lchild, head, prev, flag);
    if (flag == 0)
    {
        flag = 1;
        head = root;
        prev = root;
    }
    else
    {
        prev->rchild = root;
        prev->rchild->lchild = prev;
        prev = prev->rchild;
    }
    Find(root->rchild, head, prev, flag);
}
node *ConvertToDLL(struct node *root)
{
    node *head = NULL;
    node *prev = NULL;
    int flag = 0;
    Find(root, head, prev, flag);
    return head;
}
void display(struct node *root)
{
    node *prev = NULL;
    //Forward Traversal
    while (root != NULL)
    {
        prev = root;
        cout << root->data << " ";
        root = root->rchild;
    }
    cout << endl;
    //Backward Traversal
    while (prev != NULL)
    {
        cout << prev->data << " ";
        prev = prev->lchild;
    }
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "After Converting to DLL" << endl;
    struct node *result = ConvertToDLL(root);
    display(result);
    return 0;
}
