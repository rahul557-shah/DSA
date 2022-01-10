//Remove Duplicates from a sorted linked list
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
void RemoveDuplicates(struct node *p)
{
    struct node *current = p, *next;
    while (current->next != NULL)
    {
        if (current->data != current->next->data)
            current = current->next;
        else
        {
            next = current->next->next;
            free(current->next);
            current->next = next;
        }
    }
}
int main()
{
    int n, k;
    printf("Enter the size:");
    scanf("%d", &n);
    create(first, n);
    printf("The linked list is\n");
    display(first);
    RemoveDuplicates(first);
    printf("\nAfter Removing Duplicates:\n");
    display(first);
    return 0;
}