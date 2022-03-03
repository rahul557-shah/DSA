// Convert a sorted List to BST(Leetcode Q.109)
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int data;
    struct ListNode *next;
} *head = NULL;
struct TreeNode
{
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};
void create(struct ListNode *p, int n)
{
    int x;
    struct ListNode *t, *temp;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    cout << "Enter the data: ";
    cin >> x;
    head->data = x;
    head->next = NULL;
    temp = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct ListNode *)malloc(sizeof(struct ListNode));
        cout << "Enter the data: ";
        cin >> x;
        t->data = x;
        t->next = NULL;
        temp->next = t;
        temp = temp->next;
    }
}
void display(struct ListNode *p)
{
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("null");
}
void Preorder(TreeNode *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}
// Time->O(n)
// Space->O(n)
TreeNode *convertToBST(ListNode *head)
{
    if (!head)
        return NULL;
    else if (!head->next)
        return new TreeNode(head->data);
    ListNode *slow = head, *fast = head, *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *root = new TreeNode(slow->data);
    prev->next = NULL;
    root->left = convertToBST(head);
    if (slow->next)
        root->right = convertToBST(slow->next);
    return root;
}
int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    create(head, n);
    cout << "The linked list is\n";
    display(head);
    TreeNode *res = convertToBST(head);
    cout << "\nThe BST in PreOrder is: " << endl;
    Preorder(res);
    return 0;
}