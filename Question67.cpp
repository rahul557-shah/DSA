//Minimum number of operations to make an array palindromic
#include <bits/stdc++.h>
using namespace std;
int MinOperations(int A[], int n)
{
    int ans = 0;
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (A[i] == A[j])
        {
            i++;
            j--;
        }
        else if (A[i] < A[j])
        {
            i++;
            A[i] = A[i] + A[i - 1];
            ans++;
        }
        else
        {
            j--;
            A[j] = A[j] + A[j + 1];
            ans++;
        }
    }
    return ans;
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
    cout << "\nMinimum Number of operations is: " << MinOperations(A, n) << endl;
    return 0;
}