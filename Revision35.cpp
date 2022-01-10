//Remove LinkedList element(Leetcode Q203)
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
} *first = NULL;
void create(struct node *p, int n)
{
    int x;
    struct node *t, *temp;
    first = (struct node *)malloc(sizeof(struct node));
    cout << "Enter the data: " << endl;
    cin >> x;
    first->data = x;
    first->next = NULL;
    temp = first;
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
node *RemoveElement(node *first, int val)
{
    if (first != NULL && first->data == val)
        first = first->next;
    node *current = first;
    while (current->next != NULL)
    {
        if (current->next->data == val)
            current->next = current->next->next;
        else
            current = current->next;
    }
    return first;
}
int main()
{
    int n, x;
    cout << "Enter the size: " << endl;
    cin >> n;
    create(first, n);
    cout << "The linked list is" << endl;
    display(first);
    cout << "Enter the element to be removed: " << endl;
    cin >> x;
    node *result = RemoveElement(first, x);
    cout << "After Removing the element: " << endl;
    display(result);
    return 0;
}