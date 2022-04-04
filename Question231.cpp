// Swap Kth nodes from the ends (Leetcode Q.1721 and GFG)
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    struct Node *next;

    Node() : data(0), next(nullptr){};
    Node(int x) : data(x), next(nullptr){};
};
void create(Node *&first, int n)
{
    int x;
    Node *t, *temp;
    cout << "Enter the value: " << endl;
    cin >> x;
    first = new Node(x);
    temp = first;
    for (int i = 1; i < n; i++)
    {
        cout << "Enter the value: " << endl;
        cin >> x;
        t = new Node(x);
        temp->next = t;
        temp = temp->next;
    }
}
void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "null";
    cout << endl;
}
// Time->O(n)
// Space->O(1)
struct Node *swapNodesLeetcode(struct Node *p, int n, int k)
{
    if (k > n)
        return p;
    struct Node *left = p, *right = p, *curr = p;
    int count = 1;
    while (curr != NULL)
    {
        if (count < k)
            left = left->next;
        if (count > k)
            right = right->next;
        count++;
        curr = curr->next;
    }
    swap(left->data, right->data);
    return p;
}
// Time->O(n)
// Space->O(1)
Node *swapNodesGFG(Node *p, int n, int k)
{
    if (k > n)
        return p;
    if (k == (n - k + 1))
        return p;
    Node *start = p, *start_prev = NULL;
    for (int i = 1; i < k; i++)
    {
        start_prev = start;
        start = start->next;
    }
    Node *end = p, *end_prev = NULL;
    for (int i = 1; i < (n - k + 1); i++)
    {
        end_prev = end;
        end = end->next;
    }
    if (start_prev != NULL)
        start_prev->next = end;
    if (end_prev != NULL)
        end_prev->next = start;
    Node *temp = start->next;
    start->next = end->next;
    end->next = temp;

    if (k == 1)
        p = end;
    if (k == n)
        p = start;
    return p;
}
int main()
{
    int n, k;
    Node *first = NULL;
    first = new Node();
    cout << "Enter the size: " << endl;
    cin >> n;
    create(first, n);
    cout << "The linked list is: " << endl;
    display(first);
    cout << "Enter the value of k: " << endl;
    cin >> k;
    cout << "After Swapping: " << endl;
    struct Node *res = swapNodesLeetcode(first, n, k);
    display(res);
    return 0;
}