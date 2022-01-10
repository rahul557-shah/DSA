//Find the intersection point of two linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;
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
int count(struct node *temp)
{
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}
//Using lenght of both linekdlists
int getInersection(struct node *p, struct node *q)
{
    struct node *ptr1 = p, *ptr2 = q;
    int c1 = count(first);
    int c2 = count(second);
    int d = abs(c1 - c2);
    if (c1 > c2)
    {
        for (int i = 0; i < d; i++)
            ptr1 = ptr1->next;
    }
    else
    {
        for (int i = 0; i < d; i++)
            ptr2 = ptr2->next;
    }
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (ptr1 != NULL)
        return ptr1->data;
    return -1;
}
//Without using length
int getIntersectionPoint(struct node *p, struct node *q)
{
    struct node *ptr1 = p, *ptr2 = q;
    if (ptr1 == NULL || ptr2 == NULL)
        return -1;
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if (ptr1 == ptr2)
            return ptr1->data;
        if (ptr1 == NULL)
            ptr1 = q;
        if (ptr2 == NULL)
            ptr2 = p;
    }
    return ptr1->data;
}
void display(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int n;
    printf("Enter the size of first list: ");
    scanf("%d", &n);
    create(n);
    printf("Enter the size of second list: ");
    scanf("%d", &n);
    create2(n);
    first->next->next = second->next->next->next;
    display(first);
    printf("\n");
    display(second);
    printf("\nIntersection Node is: %d", getIntersectionPoint(first, second));
    return 0;
}