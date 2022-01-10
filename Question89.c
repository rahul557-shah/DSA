//Find the pair in a doubly linked list whose sum is equal to the given 'sum'
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
void countPairs(struct node *p, int sum)
{
    struct node *f = p, *s = p;
    while (s->next != NULL)
        s = s->next;
    bool flag = false;
    while (f != s && s->next != f)
    {
        if ((f->data + s->data) == sum)
        {
            flag = true;
            printf("(%d , %d) ", f->data, s->data);
            f = f->next;
            s = s->prev;
        }
        else
        {
            if ((f->data + s->data) < sum)
                f = f->next;
            else
                s = s->prev;
        }
    }
    if (flag == false)
        printf("No pair Sum");
}
int main()
{
    int n, sum;
    printf("Enter the size: ");
    scanf("%d", &n);
    create(first, n);
    printf("The doubly linked list is\n");
    display(first);
    printf("\n");
    printf("Enter the sum: ");
    scanf("%d", &sum);
    printf("The pair sum is\n");
    countPairs(first, sum);
    return 0;
}