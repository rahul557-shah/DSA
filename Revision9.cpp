// Maximum Sum Contiguous Subarray
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
int LargestSum(int A[], int n)
{
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum < 0)
            sum = 0;
        maxi = max(sum, maxi);
    }
    return maxi;
}
int main()
{
    int n;
    cout << "Enter the size" << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The array is: " << endl;
    printArray(A, n);
    cout << "Maximum sum of Contiguous Subarray is: " << LargestSum(A, n) << endl;
    return 0;
}