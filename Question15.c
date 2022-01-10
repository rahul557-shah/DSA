//Rotate the LinkedList
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
struct node *Rotate(struct node *p, int k)
{
    struct node *q = NULL, *r = p, *temp = p;
    int i = 0, len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    if (k > len)
        return NULL;
    if (k == 0 || k == len)
        return first;
    while (i < k)
    {
        q = p;
        p = p->next;
        i++;
    }
    q->next = NULL;
    first = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    //Make next of p as first of previous LinkedList
    p->next = r;
    return first;
}

int main()
{
    int n, k;
    printf("Enter the size:");
    scanf("%d", &n);
    create(first, n);
    printf("The linked list is\n");
    display(first);
    printf("\nEnter the value of k:");
    scanf("%d", &k);
    printf("After Rotating\n");
    Rotate(first, k);
    display(first);
    return 0;
}