//Add two numbers representd by linked lists (GFG)
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL;
void create(int n)
{
    int data;
    struct node *temp, *newnode;
    first = (struct node *)malloc(sizeof(struct node));
    if (first == NULL)
        printf("Memory cannot be allocated!!!");
    else
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        first->data = data;
        first->next = NULL;
        temp = first;
    }
    for (int i = 1; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}
void create2(int n)
{
    int data;
    struct node *temp, *newnode;
    second = (struct node *)malloc(sizeof(struct node));
    if (second == NULL)
        printf("Memory cannot be allocated!!!");
    else
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        second->data = data;
        second->next = NULL;
        temp = second;
    }
    for (int i = 1; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
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
struct node *AddTwoNumbers(struct node *first, struct node *second)
{
    first = reverse(first);
    second = reverse(second);
    int s = 0;
    int c = 0;
    struct node *result = NULL, *current = NULL, *temp;
    while (first != NULL || second != NULL)
    {
        s = c + (first ? first->data : 0) + (second ? second->data : 0);
        c = (s >= 10) ? 1 : 0;
        s = s % 10;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = s;
        temp->next = NULL;
        if (result == NULL)
            result = temp;
        else
            current->next = temp;
        current = temp;
        if (first != NULL)
            first = first->next;
        if (second != NULL)
            second = second->next;
    }
    if (c > 0)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = NULL;
        current->next = temp;
        current = temp;
    }
    result = reverse(result);
    return result;
}
int main()
{
    int n;
    printf("Enter the size of first linked list: ");
    scanf("%d", &n);
    create(n);
    printf("The first linked list is\n");
    display(first);
    printf("\nEnter the size of second linked list: ");
    scanf("%d", &n);
    create2(n);
    printf("The second linked list is\n");
    display(second);
    printf("\n");
    printf("After Adding two numbers:\n");
    struct node *res;
    res = AddTwoNumbers(first, second);
    display(res);
    return 0;
}