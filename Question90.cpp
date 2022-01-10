//Merge k sorted singly linked lists
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct Node *newNode(int data)
{
    struct Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
struct Node *Merge(struct Node *a, struct Node *b)
{
    struct Node *res = NULL;
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (a->data <= b->data)
    {
        res = a;
        res->next = Merge(a->next, b);
    }
    else
    {
        res = b;
        res->next = Merge(a, b->next);
    }
    return res;
}
//Time->O(nlogk)
//Space->O(1)
struct Node *mergeKSortedLists(struct Node *arr[], int k)
{
    int i;
    int j;
    int last = k - 1;
    while (last != 0)
    {
        i = 0;
        j = last;
        while (i < j)
        {
            arr[i] = Merge(arr[i], arr[j]);
            i++;
            j--;
            if (i >= j)
                last = j;
        }
    }
    return arr[0];
}
void printList(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    int k = 3;
    int n = 4;
    Node *arr[k];
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
    struct Node *head = mergeKSortedLists(arr, k);
    printList(head);
    return 0;
}
