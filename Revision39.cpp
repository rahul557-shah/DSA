//Remove Nth node from last(Leetcode Q19)
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
//Time->O(2n)
//Space->O(1)
node *NthFromLast(node *head, int n)
{
    if (head == NULL || head->next == NULL || n == 0)
        return head;
    node *curr = head;
    int len = 1;
    while (curr->next != NULL)
    {
        curr = curr->next;
        len++;
    }
    if (len == n)
    {
        node *temp = head;
        head = head->next;
        delete (temp);
    }
    else
    {
        curr = head;
        for (int i = 1; i < len - n; i++)
        {
            curr = curr->next;
        }
        node *temp = curr->next;
        curr->next = curr->next->next;
        delete (temp);
    }
    return head;
}
//Optimised
//Time->O(n)
//Space->O(1)
node *deleteNth(node *head, int n)
{
    node *start;
    start->next = head;
    node *slow = start, *fast = start;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    node *temp = slow->next;
    slow->next = slow->next->next;
    delete (temp);
    return start->next;
}
int main()
{
    int n, x;
    cout << "Enter the size: " << endl;
    cin >> n;
    create(head, n);
    cout << "The linked list is" << endl;
    display(head);
    cout << "Enter the value of x " << endl;
    cin >> x;
    node *result = deleteNth(head, x);
    cout << "After Deleting the element: " << endl;
    display(result);
    return 0;
}