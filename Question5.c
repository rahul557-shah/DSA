//Create a singly linked list. Swap every two adjacent nodes and return the reordered list.
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
void swap(struct node *p)
{
    if (p == NULL || p->next == NULL)
        return;
    struct node *temp, *q = NULL;
    while (p != NULL && p->next != NULL)
    {
        temp = p->next;
        p->next = temp->next;
        temp->next = p;
        if (q == NULL)
            first = temp;
        else
            q->next = temp;
        q = p;
        p = p->next;
    }
}
int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create(first, n);
    printf("The LinkedList is:\n");
    display(first);
    swap(first);
    printf("\nAfter Swapping:\n");
    display(first);
    return 0;
}