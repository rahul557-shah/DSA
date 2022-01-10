//Reverse a doubly linked list in a group of given size 'k'
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
struct node *reverseInGroup(struct node *p, int k)
{
    int count = 0;
    struct node *next, *prev = NULL, *curr = p;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL)
    {
        p->next = reverseInGroup(next, k);
        p->next->prev = p;
    }
    return prev;
}
int main()
{
    int n, N;
    printf("Enter the size: ");
    scanf("%d", &n);
    create(first, n);
    printf("The doubly linked list is\n");
    display(first);
    printf("\n");
    printf("Enter the number of nodes to be rotated: ");
    scanf("%d", &N);
    struct node *res = reverseInGroup(first, N);
    printf("After Reversing:\n");
    display(res);
    return 0;
}