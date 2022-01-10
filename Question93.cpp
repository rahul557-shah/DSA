// Sort a k sorted doubly linked list
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct compare
{
    bool operator()(struct Node *first, struct Node *second)
    {
        return first->data > second->data;
    }
};
//Time->O(nlogk)
//Space->O(k)
struct Node *sortKSortedDLL(struct Node *head, int k)
{
    priority_queue<Node *, vector<Node *>, compare> pq;
    struct Node *newHead = NULL, *curr;
    for (int i = 0; head != NULL && i <= k; i++)
    {
        pq.push(head);
        head = head->next;
    }
    while (!pq.empty())
    {
        if (newHead == NULL)
        {
            newHead = pq.top();
            pq.top()->prev = NULL;
            curr = pq.top();
        }
        else
        {
            curr->next = pq.top();
            pq.top()->prev = NULL;
            curr = pq.top();
        }
        pq.pop();
        while (head != NULL)
        {
            pq.push(head);
            head = head->next;
        }
    }
    curr->next = NULL;
    return newHead;
}
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
void printList(struct Node *head)
{
    if (head == NULL)
        cout << "Doubly Linked list empty";

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    struct Node *head = NULL;
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);

    int k = 2;

    cout << "Original Doubly linked list:\n";
    printList(head);
    head = sortKSortedDLL(head, k);
    cout << "\nDoubly linked list after sorting:\n";
    printList(head);

    return 0;
}
