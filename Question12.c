//Detect and Remove Loop
#include <stdio.h>
#include <stdlib.h>
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
    printf("Enter the data: ");
    scanf("%d", &x);
    first->data = x;
    first->next = NULL;
    temp = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &x);
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
        printf("%d->", p->data);
        p = p->next;
    }
    printf("null");
}
//First Method
void removeLoop(struct node *loopnode, struct node *p)
{
    struct node *ptr1, *ptr2;
    ptr1 = p;
    while (1)
    {
        ptr2 = loopnode;
        while (ptr2->next != loopnode && ptr2->next != ptr1)
            ptr2 = ptr2->next;
        if (ptr2->next = ptr1)
            break;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
}
//Second More Effective Method
void RemoveLoop(struct node *loopnode, struct node *p)
{
    int k = 1;
    struct node *ptr1 = loopnode;
    struct node *ptr2 = loopnode;
    while (ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        k++;
    }
    ptr1 = p;
    ptr2 = p;
    for (int i = 0; i < k; i++)
    {
        ptr2 = ptr2->next;
    }
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
    ptr2->next = NULL;
}
int DetectAndRemoveLoop(struct node *q)
{
    struct node *slow = q;
    struct node *fast = q;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            RemoveLoop(slow, q);
            //removeLoop(slow,q);
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    printf("Enter the size:");
    scanf("%d", &n);
    create(first, n);
    printf("The linked list is\n");
    display(first);
    //Forming A Loop
    first->next->next->next->next = first->next->next;
    DetectAndRemoveLoop(first);
    printf("\nLinked List after removing loop\n");
    display(first);
    return 0;
}