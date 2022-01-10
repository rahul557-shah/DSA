//Multiply two linked lists
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
long long Multiply(struct node *head1, struct node *head2)
{
    long long N = 1000000007;
    long long num1 = 0;
    long long num2 = 0;
    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            num1 = ((num1 * 10) % N) + head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            num2 = ((num2 * 10) % N) + head2->data;
            head2 = head2->next;
        }
    }
    return ((num1 % N) * (num2 % N)) % N;
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
    printf("\nAfter Multiplying two linked lists: %d", Multiply(first, second));
    return 0;
}