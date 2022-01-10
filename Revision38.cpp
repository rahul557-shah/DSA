//Rotate a Linkedlist(Leetcode Q61)
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
} *head = NULL;
void create(struct node *p, int n)
{
    int x;
    struct node *t, *temp;
    head = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the data: " << endl;
    cin >> x;
    head->data = x;
    head->next = NULL;
    temp = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        cin >> x;
        t->data = x;
        t->next = NULL;
        temp->next = t;
        temp = temp->next;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "null";
    cout << endl;
}
//Time->O(n)
//Space->O(1)
node *Rotate(node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    node *curr = head;
    int len = 1;
    while (curr->next != NULL)
    {
        curr = curr->next;
        len++;
    }
    curr->next = head;
    k = k % len;
    k = len - k;
    while (k != 0)
    {
        curr = curr->next;
        k--;
    }
    head = curr->next;
    curr->next = NULL;
    return head;
}
int main()
{
    int n, x;
    cout << "Enter the size: " << endl;
    cin >> n;
    create(head, n);
    cout << "The linked list is" << endl;
    display(head);
    cout << "Enter the number of rotations: " << endl;
    cin >> x;
    node *result = Rotate(head, x);
    cout << "After Rotating the element: " << endl;
    display(result);
    return 0;
}