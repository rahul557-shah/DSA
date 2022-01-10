//Check LinkedList Cycle(Leetcode Q141) and
//Reverse LinkedList(Leetcode Q206) and
//Remove Duplicates from sorted Linkedlist(Leetcode Q83)
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
bool hasCycle(node *head)
{
    if (head == NULL)
        return NULL;
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
//Time->O(n)
//Space->O(1)
node *Reverse(node *head)
{
    node *curr = head, *prev = NULL;
    while (curr != NULL)
    {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
//Time->O(n)
//Space->O(1)
node *RemoveDuplicates(node *head)
{
    node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data != curr->next->data)
            curr = curr->next;
        else
        {
            node *next = curr->next->next;
            delete (curr->next);
            curr->next = next;
        }
    }
    return head;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    create(head, n);
    cout << "The linked list is" << endl;
    display(head);
    if (hasCycle(head))
        cout << "Has cycle!! " << endl;
    else
        cout << "No cycle!! " << endl;
    /*cout << "After Reversing: " << endl;
    node *result = Reverse(head);
    display(result);*/
    cout << "After Removing Duplicates: " << endl;
    node *ans = RemoveDuplicates(head);
    display(ans);
    return 0;
}