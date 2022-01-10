
//Smallest Subarray greater than given sum
#include <bits/stdc++.h>
using namespace std;
//Time->O(n^2)
int SmallestSubArray(int A[], int n, int x)
{
    int mi = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += A[j];
            if (sum > x)
                mi = min(mi, j - i + 1);
        }
    }
    return mi;
}
//Time->O(n)
//Space->O(1)
int SmallestSubA(int A[], int n, int x)
{
    int i, j, sum;
    i = j = sum = 0;
    int mi = INT_MAX;
    while (i <= j && j < n)
    {
        while (sum <= x && j < n)
        {
            sum += A[j];
            j++;
        }
        while (sum > x && i <= j)
        {
            mi = min(mi, j - i);
            sum -= A[i];
            i++;
        }
    }
    return mi;
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
    int x;
    cout << "\nEnter the sum" << endl;
    cin >> x;
    cout << "Smallest Subarray is:" << SmallestSubA(A, n, x) << endl;
    return 0;
}