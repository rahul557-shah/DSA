//Clone a linked list with next and random pointers
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *random;
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
    first->random = NULL;
    temp = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &x);
        t->data = x;
        t->next = NULL;
        t->random = NULL;
        temp->next = t;
        temp = temp->next;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("\nData = %d ,Random = %d ", p->data, p->random->data);
        p = p->next;
    }
}
//Time->O(n)
//Space->O(1)
struct node *Clone(struct node *p)
{
    struct node *curr = p, *temp;
    while (curr != NULL)
    {
        temp = curr->next;
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = curr->data;
        newnode->next = temp;
        curr->next = newnode;
        curr = temp;
    }
    curr = p;
    while (curr != NULL)
    {
        curr->next->random = curr->random ? curr->random->next : NULL;
        curr = curr->next->next;
    }
    struct node *original = p;
    struct node *copy = p->next;
    temp = copy;
    while (original != NULL && copy != NULL)
    {
        original->next = original->next->next;
        copy->next = copy->next ? copy->next->next : NULL;
        original = original->next;
        copy = copy->next;
    }
    return temp;
}
int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    create(first, n);
    first->random = first->next->next;
    first->next->random = first;
    first->next->next->random = first->next->next->next;
    first->next->next->next->random = first->next;
    printf("The linked list is:\n");
    display(first);
    printf("\n");
    struct node *res = Clone(first);
    printf("The Clone Linked list is:\n");
    display(res);
    return 0;
}