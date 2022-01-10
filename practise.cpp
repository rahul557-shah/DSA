//Binary Search Algorithm
#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int A[], int l, int h, int key)
{
    if (l == h)
    {
        if (key == A[l])
            return l;
        else
            return -1;
    }
    else
    {
        int mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return BinarySearch(A, l, mid, key);
        else
            return BinarySearch(A, mid + 1, h, key);
    }
    return -1;
}
int main()
{
    int n, key;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The Array is: " << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\nEnter the key to be searched: " << endl;
    cin >> key;
    cout << "The element is at: " << BinarySearch(A, 0, n - 1, key) << endl;
    return 0;
}