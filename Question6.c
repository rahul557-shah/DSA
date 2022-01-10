/*Create a singly linked-list. The list can be represented as:
  L0 -> L1 -> … → Ln - 1 -> Ln
  Reorder the list to be in the following form:
  L0 -> Ln -> L1 → Ln - 1 -> L2 -> Ln - 2 -> …*/
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
struct node *reverse(struct node *curr)
{
    struct node *prev = NULL, *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
//Alernate Merge two halves of the list
void merge(struct node *l1, struct node *l2)
{
    while (l1 != NULL)
    {
        struct node *l1_next = l1->next;
        struct node *l2_next = l2->next;
        l1->next = l2;
        if (l1->next == NULL)
            break;
        l2->next = l1_next;
        l1 = l1_next;
        l2 = l2_next;
    }
}
void Interchange(struct node *p)
{
    //Finding the middle term
    struct node *slow = first, *fast = first, *prev = NULL;
    if (p == NULL || p->next == NULL)
        return;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    struct node *l1 = first;
    struct node *l2 = reverse(slow);
    merge(l1, l2);
}
int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create(first, n);
    printf("The LinkedList is:\n");
    display(first);
    printf("\nAfter Rearranging:\n");
    Interchange(first);
    display(first);
    return 0;
}