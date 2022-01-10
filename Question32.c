//Recursive Function For Intersection of two sorted Linked List
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *start1 = NULL, *start2 = NULL, *start3 = NULL;
void create(struct node **start, int data)
{
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (*start == NULL)
        *start = newnode;
    else
    {
        temp = *start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void display(struct node **start)
{
    struct node *temp = *start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
struct node *RecursiveIntersection(struct node **start1, struct node **start2)
{
    struct node *temp1 = *start1, *temp2 = *start2;
    struct node *p;
    if (temp1 == NULL || temp2 == NULL)
        return NULL;
    else
    {
        if (temp1->data < temp2->data)
            return RecursiveIntersection(&temp1->next, &temp2);
        else if (temp1->data > temp2->data)
            return RecursiveIntersection(&temp1, &temp2->next);
        else
        {
            p = (struct node *)malloc(sizeof(struct node));
            p->data = temp1->data;
            p->next = RecursiveIntersection(&temp1->next, &temp2->next);
        }
    }
    return p;
}
int main()
{
    struct node *result;
    int data, ch;
    do
    {
        printf("\n1. Enter data in first linked list:");
        printf("\n2. Enter data in second linked list:");
        printf("\n3. Display first list: ");
        printf("\n4 Display second list:");
        printf("\n5. Intersection: ");
        printf("\n6. Display the resultant:");
        printf("\n7. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d", &data);
            create(&start1, data);
            break;
        case 2:
            printf("Enter the data:");
            scanf("%d", &data);
            create(&start2, data);
            break;
        case 3:
            printf("\nThe first list is:\n");
            display(&start1);
            break;
        case 4:
            printf("\nThe second list is:\n");
            display(&start2);
            break;
        case 5:
            result = RecursiveIntersection(&start1, &start2);
            break;
        case 6:
            printf("\nThe result is:\n");
            display(&result);
            break;
        }
    } while (ch < 7);

    return 0;
}