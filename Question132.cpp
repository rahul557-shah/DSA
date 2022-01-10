//Check whether two binary trees are isomorphic or not
#include <bits/stdc++.h>
using namespace std;
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root1 = NULL, *root2 = NULL;
void Treecreate(node *&root)
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
void Inorder(node *root)
{
    if (root != NULL)
    {
        Inorder(root->lchild);
        cout << root->data << " ";
        Inorder(root->rchild);
    }
}
bool isIsomorphic(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->data != root2->data)
        return false;
    bool a = isIsomorphic(root1->lchild, root2->lchild) && isIsomorphic(root1->rchild, root2->rchild);
    bool b = isIsomorphic(root1->lchild, root2->rchild) && isIsomorphic(root1->rchild, root2->lchild);
    return a || b;
}
int main()
{
    cout << "Create first binary tree" << endl;
    Treecreate(root1);
    cout << "Create second binary tree" << endl;
    Treecreate(root2);
    cout << "The Inorder Traversal of the first Binary tree is: " << endl;
    Inorder(root1);
    cout << "\nThe Inorder Traversal of the second Binary tree is: " << endl;
    Inorder(root2);
    cout << endl;
    if (isIsomorphic(root1, root2))
        cout << "Yes two binary trees are Isomorphic" << endl;
    else
        cout << "Not Isomorphic" << endl;
    return 0;
}
