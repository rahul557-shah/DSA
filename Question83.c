//Segregate even and odd nodes in a linked list
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
struct node *Segregate(struct node *p)
{
    struct node *even = NULL, *odd = NULL;
    struct node *e = NULL, *o = NULL;
    while (p != NULL)
    {
        if (p->data % 2 == 0)
        {
            if (even == NULL)
            {
                even = p;
                e = p;
            }
            else
            {
                e->next = p;
                e = e->next;
            }
        }
        else
        {
            if (odd == NULL)
            {
                odd = p;
                o = p;
            }
            else
            {
                o->next = p;
                o = o->next;
            }
        }
        p = p->next;
    }
    if (e != NULL)
        e->next = odd;
    if (o != NULL)
        o->next = NULL;
    if (even != NULL)
        return even;
    return odd;
}
int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    create(first, n);
    printf("The linked list is:\n");
    display(first);
    printf("\n");
    struct node *res = Segregate(first);
    printf("\nAfter Segregating even and odd:\n");
    display(res);
    return 0;
}