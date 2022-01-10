//Reverse the linked list in a group of given size k(LeetCode Q25)
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
struct node *reverse(struct node *p, int k)
{
    struct node *current = p, *prev = NULL, *next = NULL;
    int count = 0;
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    int len = 0;
    struct node *temp = next;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    if (next != NULL && k <= len)
    {
        p->next = reverse(next, k);
        return prev;
    }
    else
    {
        p->next=next;
        return prev;
    }
}
int main()
{
    int n, k;
    printf("Enter the size:");
    scanf("%d", &n);
    create(first, n);
    printf("The linked list is\n");
    display(first);
    printf("\nEnter the value of k:");
    scanf("%d", &k);
    first = reverse(first, k);
    printf("After reversing in a group\n");
    display(first);
    return 0;
}