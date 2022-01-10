//Palindromic Linkedlist(Leetcode Q234)
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
node *reverseList(node *head)
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
bool isPalindrome(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    slow = slow->next;
    fast = head;
    while (slow != NULL)
    {
        if (fast->data != slow->data)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}
int main()
{
    int n, x;
    cout << "Enter the size: " << endl;
    cin >> n;
    create(head, n);
    cout << "The linked list is" << endl;
    display(head);
    if (isPalindrome(head))
        cout << "The Linkedlist is Palindrome!!" << endl;
    else
        cout << "Not Palindrome!!" << endl;
    return 0;
}