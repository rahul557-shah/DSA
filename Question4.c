//Group nodes of all the odd indices together followed by nodes of even indices
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
void Interchange(struct node *p, struct node *q)
{
    struct node *temp = q;
    while (p != NULL && q!=NULL && q->next != NULL)
    {
        p->next = q->next;
        p = p->next;
        q->next = p->next;
        q = q->next;
    }
    p->next = temp;
}
int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create(first, n);
    printf("The LinkedList is:\n");
    display(first);
    Interchange(first, first->next);
    printf("\nAfter Interchanging:\n");
    display(first);
    return 0;
}