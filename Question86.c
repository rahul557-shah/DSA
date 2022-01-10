//MergeSort a linked list
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
struct node *MergeBoth(struct node *l1, struct node *l2)
{
    struct node *res = NULL;
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    if (l1->data <= l2->data)
    {
        res = l1;
        res->next = MergeBoth(l1->next, l2);
    }
    else
    {
        res = l2;
        res->next = MergeBoth(l1, l2->next);
    }
    return res;
}
void FindMiddle(struct node *curr, struct node **l1, struct node **l2)
{
    struct node *slow, *fast;
    slow = curr;
    fast = curr->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *l1 = curr;
    *l2 = slow->next;
    slow->next = NULL;
}
void MergeSort(struct node **p)
{
    struct node *curr = *p;
    struct node *first, *second;
    if (curr == NULL || curr->next == NULL)
        return;
    FindMiddle(curr, &first, &second);

    MergeSort(&first);
    MergeSort(&second);

    *p = MergeBoth(first, second);
}
int main()
{
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);
    create(first, n);
    printf("The linked list is:\n");
    display(first);
    printf("\n");
    printf("After Merge Sorting:\n");
    MergeSort(&first);
    display(first);
    return 0;
}