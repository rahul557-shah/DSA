//Delete nodes having greater values on right
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
struct node *reverse(struct node *p)
{
    struct node *current = p, *prev = NULL;
    while (current != NULL)
    {
        struct node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
struct node *DeleteSmaller(struct node *p)
{
    p = reverse(p);
    struct node *curr = p, *prev = p;
    int ma = p->data;
    p = p->next;
    while (p != NULL)
    {
        if (p->data >= ma)
        {
            ma = p->data;
            prev = p;
            p = p->next;
        }
        else
        {
            prev->next = p->next;
            p = prev->next;
        }
    }
    p = reverse(curr);
    return p;
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
    struct node *res = DeleteSmaller(first);
    printf("After Deleting:\n");
    display(res);
    return 0;
}