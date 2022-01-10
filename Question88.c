//Count triplets in a sorted doubly linked list
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
int CountPair(struct node *f, struct node *s, int sum)
{
    int count = 0;
    while (f != s && s->next != f)
    {
        if (f->data + s->data == sum)
        {
            count++;
            f = f->next;
            s = s->prev;
        }
        else if (f->data + s->data < sum)
            f = f->next;
        else
            s = s->prev;
    }
    return count;
}
int CountTriplet(struct node *p, int value)
{
    struct node *curr, *last = p, *begin;
    int count = 0;
    if (p == NULL)
        return 0;
    while (last->next != NULL)
        last = last->next;
    for (curr = p; curr != NULL; curr = curr->next)
    {
        begin = curr->next;
        count += CountPair(begin, last, value - curr->data);
    }
    return count;
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
    printf("The number of triplets is: %d", CountTriplet(first, sum));
    return 0;
}