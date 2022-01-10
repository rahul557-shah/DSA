//Check if the tree is balanced or not
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
vector<int> LevelOrder(struct node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        res.push_back(temp->data);
        if (temp->lchild)
            q.push(temp->lchild);
        if (temp->rchild)
            q.push(temp->rchild);
        q.pop();
    }
    return res;
}
int height(struct node *root)
{
    if (root != NULL)
    {
        int x = height(root->lchild);
        int y = height(root->rchild);
        return 1 + max(x, y);
    }
    return 0;
}
//Time->O(n)
//Space->O(height)[With Stack Frame]
bool CheckBalanced(struct node *root)
{
    if (root == NULL)
        return true;
    int lh, rh;
    lh = height(root->lchild);
    rh = height(root->rchild);
    if ((abs(lh - rh) <= 1) && CheckBalanced(root->lchild) && CheckBalanced(root->rchild))
        return true;
    return false;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    vector<int> result;
    result = LevelOrder(root);
    cout << "Level Order traversal of binary tree is \n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    if (CheckBalanced(root))
        cout << "\nThe Binary Tree is balanced" << endl;
    else
        cout << "\nThe Binary Tree isnot balanced" << endl;
    return 0;
}
