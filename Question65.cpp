
// Three way partitioning of an Array(same as sort 0's, 1's and 2's)
#include <bits/stdc++.h>
using namespace std;
// Time->O(n)
// Space->O(1)
void ThreewayPartition(int A[], int n, int a, int b)
{
    int low = 0, high = n - 1;
    for (int mid = 0; mid <= high;)
    {
        if (A[mid] < a)
        {
            swap(A[low], A[mid]);
            low++;
            mid++;
        }
        else if (A[mid] > b)
        {
            swap(A[mid], A[high]);
            high--;
        }
        else
            mid++;
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    int x, y;
    cout << "\nEnter the limit" << endl;
    cin >> x >> y;
    ThreewayPartition(A, n, x, y);
    cout << "After Partition the array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}