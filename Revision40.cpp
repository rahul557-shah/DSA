//Merge two Sorted Linkedlist(Leetcode Q21)
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL;
void create(int n)
{
    int data;
    struct node *temp, *newnode;
    first = (struct node *)malloc(sizeof(struct node));
    if (first == NULL)
        cout << "Memory cannot be allocated!!!" << endl;
    else
    {
        cout << "Enter the data: " << endl;
        cin >> data;
        first->data = data;
        first->next = NULL;
        temp = first;
    }
    for (int i = 1; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cin >> data;
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}
void create2(int n)
{
    int data;
    struct node *temp, *newnode;
    second = (struct node *)malloc(sizeof(struct node));
    if (second == NULL)
        cout << "Memory cannot be allocated!!!" << endl;
    else
    {
        cout << "Enter the data: " << endl;
        cin >> data;
        second->data = data;
        second->next = NULL;
        temp = second;
    }
    for (int i = 1; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        cin >> data;
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
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
node *Merge(node *l1, node *l2)
{
    node *ptr1 = l1, *ptr2 = l2, *l3 = NULL, *temp = NULL;
    if (ptr1 == NULL)
        return ptr2;
    else if (ptr2 == NULL)
        return ptr1;
    if (ptr1->data <= ptr2->data)
    {
        l3 = temp = ptr1;
        ptr1 = ptr1->next;
        temp->next = NULL;
    }
    else
    {
        l3 = temp = ptr2;
        ptr2 = ptr2->next;
        temp->next = NULL;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            temp->next = ptr1;
            temp = ptr1;
            ptr1 = ptr1->next;
            temp->next = NULL;
        }
        else
        {
            temp->next = ptr2;
            temp = ptr2;
            ptr2 = ptr2->next;
            temp->next = NULL;
        }
    }
    if (ptr1 != NULL)
        temp->next = ptr1;
    if (ptr2 != NULL)
        temp->next = ptr2;
    return l3;
}
int main()
{
    int m, n;
    cout << "Enter the size of first linked list: " << endl;
    cin >> m;
    create(m);
    cout << "The first linked list is" << endl;
    display(first);
    cout << "Enter the size of second linked list: " << endl;
    cin >> n;
    create2(n);
    cout << "The second linked list is" << endl;
    display(second);
    cout << "After Merging Two Linkedlist:" << endl;
    node *res = Merge(first, second);
    display(res);
    return 0;
}