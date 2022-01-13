// Find if there is subarray with sum equal to zero.
#include <bits/stdc++.h>
using namespace std;
// Time->O(n)
// Space->O(n)
bool SumZero(int a[], int n)
{
    int pre_sum = 0;
    unordered_map<int, int> mymap;
    for (int i = 0; i < n; i++)
    {
        pre_sum += a[i];
        if (pre_sum == 0 || mymap[pre_sum] == 1)
            return true;
        else
            mymap[pre_sum]++;
    }
    return false;
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
    if (SumZero(A, n))
        cout << "\nYes Subarray Found!!" << endl;
    else
        cout << "\nNot Found!" << endl;
    return 0;
}