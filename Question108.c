//Reverse a linked list-II(LEETCODE)
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
struct node *ReverseFromStartToEnd(struct node *p, int start, int end)
{
    if (p == NULL || start == end)
        return p;
    struct node *curr, *next;
    struct node dummy;
    dummy.data = 0;
    dummy.next = p;
    struct node *prev = &dummy;
    int pos = 1;
    while (pos < start)
    {
        prev = prev->next;
        pos++;
    }
    curr = prev->next;
    while (start < end)
    {
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
        start++;
    }
    return dummy.next;
}
int main()
{
    int n, start, end;
    printf("Enter the size:");
    scanf("%d", &n);
    create(first, n);
    printf("The linked list is\n");
    display(first);
    printf("\nEnter the starting position: ");
    scanf("%d", &start);
    printf("Enter the ending position: ");
    scanf("%d",&end);
    struct node *res = ReverseFromStartToEnd(first, start, end);
    printf("After Reversing:\n");
    display(res);
    return 0;
}