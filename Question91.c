//Rotate a doubly linked list by N nodes
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
struct node *rotate(struct node *p, int N)
{
    if (N == 0)
        return p;
    struct node *curr = p;
    int count = 1;
    while (count < N && curr != NULL)
    {
        curr = curr->next;
        count++;
    }
    struct node *NthNode = curr;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = p;
    p->prev = curr;
    p = NthNode->next;
    NthNode->next = NULL;
    p->prev = NULL;
    return p;
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
    struct node *res = rotate(first, N);
    printf("After Rotating:\n");
    display(res);
    return 0;
}