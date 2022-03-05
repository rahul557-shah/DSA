// Populating Next Right Pointer in each Nodes II(Leetcode Q231)
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node() : data(0), left(nullptr), right(nullptr), next(nullptr){};
    Node(int x) : data(x), left(nullptr), right(nullptr), next(nullptr){};
} *root = NULL;
void Treecreate()
{
    int x;
    struct Node *p, *t;
    queue<Node *> q;
    root = new Node();
    printf("Enter the root: ");
    scanf("%d", &x);
    root->data = x;
    root->left = NULL;
    root->right = NULL;
    root->next = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node(x);
            p->left = t;
            q.push(t);
        }
        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node(x);
            p->right = t;
            q.push(t);
        }
        q.pop();
    }
}
void PreorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
    PreorderTraversal(root->next);
}
// Approach-1
// Time->O(n)
// Space->O(n)
Node *connectNextPointer(Node *root)
{
    if (root == NULL)
        return NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        Node *dummy = new Node(0);
        while (size--)
        {
            Node *node = q.front();
            q.pop();
            dummy->next = node;
            dummy = dummy->next;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return root;
}
// Approach-2
// Time->O(n)
// Space->O(1)
Node *connectNxtPtr(Node *root)
{
    if (!root)
        return NULL;
    Node *head = root;
    while (head)
    {
        Node *dummy = new Node(0);
        Node *temp = dummy;
        while (head)
        {
            if (head->left)
            {
                temp->next = head->left;
                temp = temp->next;
            }
            if (head->right)
            {
                temp->next = head->right;
                temp = temp->next;
            }
            head = head->next;
        }
        head = dummy->next;
    }
    return root;
}
int main()
{
    cout << "Create a binary tree" << endl;
    Treecreate();
    cout << "Binary Tree is :" << endl;
    PreorderTraversal(root);
    cout << endl;
    cout << "After Connecting Next Pointer: " << endl;
    Node *res = connectNxtPtr(root);
    PreorderTraversal(res);
    return 0;
}