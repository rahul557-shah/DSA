//Clone a linked list with next and random pointers
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next, *random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random = " << ptr->random->data << endl;
        ptr = ptr->next;
    }
}
//Time->O(n)
//Space->O(1)
Node *clone(Node *start)
{
    Node *curr = start, *temp;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = start;
    while (curr != NULL)
    {
        curr->next->random = curr->random ? curr->random->next : NULL;
        curr = curr->next->next;
    }
    Node *original = start;
    Node *copy = start->next;
    temp = copy;
    while (original != NULL && copy != NULL)
    {
        original->next = original->next->next;
        copy->next = copy->next ? copy->next->next : NULL;
        original = original->next;
        copy = copy->next;
    }
    return temp;
}
int main()
{
    Node *start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);
    start->random = start->next->next;
    start->next->random = start;
    start->next->next->random = start->next->next->next->next;
    start->next->next->next->random = start->next->next->next->next;
    start->next->next->next->next->random = start->next;

    cout << "Original list : \n";
    print(start);

    cout << "\nCloned list : \n";
    Node *cloned_list = clone(start);
    print(cloned_list);

    return 0;
}
