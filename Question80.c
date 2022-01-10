//Sort 0s,1s,2s of a given linked list
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
void Sort012(struct node *p)
{
    struct node *ptr = p;
    int count[3] = {0, 0, 0};
    while (ptr != NULL)
    {
        count[ptr->data]++;
        ptr = ptr->next;
    }
    ptr = p;
    int i = 0;
    while (ptr != NULL)
    {
        if (count[i] == 0)
            i++;
        else
        {
            ptr->data = i;
            count[i]--;
            ptr = ptr->next;
        }
    }
}
int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    create(first, n);
    printf("The linked list is\n");
    display(first);
    printf("\n");
    Sort012(first);
    printf("After Sorting the list:\n");
    display(first);
    return 0;
}