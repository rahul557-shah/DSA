//Reverse a doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
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
    first->prev = NULL;
    first->next = NULL;
    temp = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &x);
        t->data = x;
        t->prev = temp;
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
struct node *reverse(struct node *p)
{
    struct node *curr = p, *prev;
    while (curr != NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}
struct node *reverseDLL(struct node *p)
{
    struct node *curr = p, *temp;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->prev;
        if (curr != NULL && curr->next == NULL)
            first = curr;
    }
    return first;
}
int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    create(first, n);
    printf("The doubly linked list is\n");
    display(first);
    printf("\n");
    struct node *res = reverseDLL(first);
    printf("After Reversing:\n");
    display(res);
    return 0;
}