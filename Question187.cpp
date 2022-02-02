// Vertical Order Traversal of a Binary Tree(Leetcode Q987)
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
// Space->(n)
void inorderTraversal(node *root, int vertical, int level, map<int, map<int, multiset<int>>> &mymap)
{
    if (root == NULL)
        return;
    inorderTraversal(root->lchild, vertical - 1, level + 1, mymap);
    mymap[vertical][level].insert(root->data);
    inorderTraversal(root->rchild, vertical + 1, level + 1, mymap);
}
// Using Inorder Traversal
vector<int> verticalTraversal(node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    map<int, map<int, multiset<int>>> mymap;
    inorderTraversal(root, 0, 0, mymap);
    for (auto i : mymap)
    {
        for (auto j : i.second)
        {
            res.insert(res.end(), j.second.begin(), j.second.end());
        }
    }
    return res;
}
// Time->O(n)
// Space->(n)
// Using Level order Traversal
vector<int> verticalUsingLevelOrder(node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    map<int, map<int, multiset<int>>> mymap;
    queue<pair<node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        node *node = p.first;
        int vertical = p.second.first;
        int level = p.second.second;
        mymap[vertical][level].insert(node->data);
        if (node->lchild)
            q.push({node->lchild, {vertical - 1, level + 1}});
        if (node->rchild)
            q.push({node->rchild, {vertical + 1, level + 1}});
    }
    for (auto i : mymap)
    {
        for (auto j : i.second)
        {
            res.insert(res.end(), j.second.begin(), j.second.end());
        }
    }
    return res;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    vector<int> result;
    cout << "Vertical Order Traversal of a Binary Tree is: " << endl;
    result = verticalUsingLevelOrder(root);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}
