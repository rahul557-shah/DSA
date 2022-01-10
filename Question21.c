//Merging two Sorted Linked List
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;
void create(int n)
{
    int data;
    struct node *temp, *newnode;
    first = (struct node *)malloc(sizeof(struct node));
    if (first == NULL)
        printf("Memory cannot be allocated!!!");
    else
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        first->data = data;
        first->next = NULL;
        temp = first;
    }
    for (int i = 1; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &data);
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
        printf("Memory cannot be allocated!!!");
    else
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        second->data = data;
        second->next = NULL;
        temp = second;
    }
    for (int i = 1; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}
void display(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("null");
}
struct node *Merge(struct node *p, struct node *q)
{
    struct node *last = NULL;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
        last->next = p;
    if (q != NULL)
        last->next = q;
    return third;
}
int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create(n);
    printf("First LinkedList is\n");
    display(first);
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    create2(n);
    printf("Second LinkedList is\n");
    display(second);
    Merge(first, second);
    printf("\nAfter Merging\n");
    display(third);
    return 0;
}