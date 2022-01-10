//Delete a node in a BST
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *insert(Node *root, int data)
{
    Node *t;
    if (root == NULL)
    {
        t = new Node();
        t->data = data;
        t->left = t->right = NULL;
        return t;
    }
    else if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
void Inorder(Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}
Node *InorderPre(Node *root)
{
    Node *p = root->left;
    if (p != NULL && p->right != NULL)
        p = p->right;
    return p;
}
Node *DeleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = DeleteNode(root->left, key);
    else if (key > root->data)
        root->right = DeleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete (root);
            return temp;
        }
        else
        {
            Node *temp = InorderPre(root);
            swap(root->data, temp->data);
            root->left = DeleteNode(root->left, key);
        }
    }
    return root;
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 3);
    insert(root, 2);
    insert(root, 5);
    insert(root, 4);
    insert(root, 10);
    insert(root, 8);
    insert(root, 15);
    insert(root, 7);
    cout << "Inorder Traversal of BST is: " << endl;
    Inorder(root);
    int key;
    cout << "\nEnter the node to be deleted: " << endl;
    cin >> key;
    Node *result = DeleteNode(root, key);
    cout << "After Deleting: " << endl;
    Inorder(result);
    return 0;
}
