
//Three way partitioning of an Array
#include <bits/stdc++.h>
using namespace std;
void ThreewayPartition(int A[], int n, int a, int b)
{
    int l = 0;
    int r = n - 1;
    for (int i = 0; i <= r; i++)
    {
        if (A[i] < a)
        {
            swap(A[i], A[l]);
            l++;
        }
        else if (A[i] > b)
        {
            swap(A[i], A[r]);
            r--;
            i--;
        }
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