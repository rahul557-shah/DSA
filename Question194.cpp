// Preorder Traversal and BST(GFG)
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
// Time->O(n)
// Space->O(n)
bool canRepresentBST(int A[], int n)
{
    int root = INT_MIN;
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (root > A[i])
            return false;
        while (!stk.empty() && stk.top() < A[i])
        {
            root = stk.top();
            stk.pop();
        }
        stk.push(A[i]);
    }
    return true;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "PreOrder is: " << endl;
    printArray(A, n);
    if (canRepresentBST(A, n))
        cout << "The Preorder can represent a BST" << endl;
    else
        cout << "The Preorder cannot represent a BST" << endl;
    return 0;
}