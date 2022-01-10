//Find the nth node from last
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
//Using Reverse of LinkedList
int NthNode(struct node *p, int n)
{
    struct node *curr = p;
    struct node *prev = NULL;
    while (curr != NULL)
    {
        struct node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    first = prev;
    int i = 1;
    while (i < n)
    {
        first = first->next;
        i++;
    }
    return first->data;
}
//Using Length of A Linked List
int Nthnode(struct node *p, int n)
{
    struct node *temp = p;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    if (len < n)
        return -1;
    else
    {
        temp = p;
        for (int i = 0; i < len - n ; i++)
            temp = temp->next;
    }
    return temp->data;
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
    printf("Nth node is %d", Nthnode(first, pos));
    return 0;
}