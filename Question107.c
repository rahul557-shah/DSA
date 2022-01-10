//Delete nth node from last
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
//Using Length of A Linked List
struct node *Nthnode(struct node *p, int n)
{
    struct node *temp = p;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    if (len < n)
        return NULL;
    else if (len == n)
    {
        struct node *temp1 = p;
        p = p->next;
        free(temp1);
        return p;
    }
    else
    {
        temp = p;
        struct node *q = NULL;
        for (int i = 0; i < len - n; i++)
        {
            q = temp;
            temp = temp->next;
        }
        q->next = temp->next;
        free(temp);
    }
    return p;
}
int main()
{
    int n, pos;
    printf("Enter the size:");
    scanf("%d", &n);
    create(first, n);
    printf("The linked list is\n");
    display(first);
    printf("\nEnter the position from last:");
    scanf("%d", &pos);
    struct node *res = Nthnode(first, pos);
    printf("After removing Nth node\n");
    display(res);
    return 0;
}