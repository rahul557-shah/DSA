// Design a linked list(Leetcode Q.707)
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};
class LinkedList
{
public:
    int size;
    Node *head;

    LinkedList()
    {
        size = 0;
        head = NULL;
    }
    // Time->O(n)
    // Space->O(1)
    int getIndex(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        Node *curr = head;
        for (int i = 0; i < index; i++)
            curr = curr->next;
        return curr->val;
    }
    // Time->O(1)
    // Space->O(1)
    void addAtBeginning(int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            size++;
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    // Time->O(n)
    // Space->O(1)
    void addAtEnd(int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            size++;
            return;
        }
        Node *curr = head;
        Node *newNode = new Node(val);
        while (curr->next)
            curr = curr->next;
        curr->next = newNode;
        size++;
    }
    // Time->O(n)
    // Space->O(1)
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index >= size)
            return;
        if (index == 0)
        {
            head = new Node(val);
            size++;
            return;
        }
        Node *prev = head, *curr;
        for (int i = 1; i < index; i++)
            prev = prev->next;
        curr = prev->next;
        Node *newNode = new Node(val);
        prev->next = newNode;
        newNode->next = curr;
        size++;
    }
    // Time->O(n)
    // Space->O(1)
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        if (index == 0)
        {
            head = head->next;
            size--;
            return;
        }
        Node *prev = head, *curr;
        for (int i = 1; i < index; i++)
            prev = prev->next;
        curr = prev->next;
        prev->next = curr->next;
        delete curr;
        size--;
    }
};
int main()
{
    int val;
    LinkedList l1 =LinkedList();
    cout << "Enter the size: " << endl;
    cin >> l1.size;
    l1.head = NULL;
    cout << "Enter the head node: " << endl;
    cin >> val;
    l1.addAtBeginning(val);
    cout << "Enter the node: " << endl;
    cin >> val;
    l1.addAtEnd(val);
    cout << "Enter the node: " << endl;
    cin >> val;
    l1.addAtEnd(val);
    cout << "Enter the node: " << endl;
    cin >> val;
    l1.addAtEnd(val);
    cout << "Value at index 2 is: " << l1.getIndex(1);
    return 0;
}