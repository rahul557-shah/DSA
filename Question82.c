//Split a circular linked list into two halves
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
    first->next = first;
    temp = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &x);
        t->data = x;
        t->next = temp->next;
        temp->next = t;
        temp = temp->next;
    }
}
void display(struct node *p)
{
    struct node *temp = p;
    do
    {
        printf("%d->", p->data);
        p = p->next;
    } while (p != temp);
    printf("null");
}
void Split(struct node *p, struct node **head1, struct node **head2)
{
    struct node *slow = p, *fast = p->next;
    while (fast != p && fast->next != p)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1 = p;
    *head2 = slow->next;
    slow->next = *head1;
    struct node *curr = *head2;
    while (curr->next != p)
    {
        curr = curr->next;
    }
    curr->next = *head2;
}
int main()
{
    int n;
    struct node *head1 = NULL, *head2 = NULL;
    printf("Enter the size: ");
    scanf("%d", &n);
    create(first, n);
    printf("The linked list is\n");
    display(first);
    printf("\n");
    Split(first, &head1, &head2);
    printf("The First Half is\n");
    display(head1);
    printf("\n");
    printf("The Second Half is\n");
    display(head2);
    printf("\n");
    return 0;
}