//Add 1 to the number represented by a linked list
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
struct node *Add1(struct node *p)
{
    p = reverse(p);
    struct node *current = p;
    while (current != NULL)
    {
        if (current->next == NULL && current->data == 9)
        {
            current->data = 1;
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->data = 0;
            temp->next = p;
            p = temp;
            current=current->next;
        }
        else if (current->data == 9)
        {
            current->data = 0;
            current = current->next;
        }
        else
        {
            current->data = current->data + 1;
            current = current->next;
            break;
        }
    }
    p = reverse(p);
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
    printf("\n");
    struct node *res = Add1(first);
    printf("After Adding One:\n");
    display(res);
    return 0;
}