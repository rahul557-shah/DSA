//Find if there is subarray with sum equal to zero.
#include <bits/stdc++.h>
using namespace std;
bool SumZero(int a[], int n)
{
    int sum = 0, flag = 0;
    unordered_map<int, int> mymap;
    for (int i = 0; i < n; i++)
    {
        //Finding PrefixSum
        sum += a[i];
        if (a[i] == 0 || sum == 0 || mymap[sum] == 1)
        {
            flag = 1;
            break;
        }
        else
            mymap[sum] = 1;
    }
    if (flag == 1)
        return true;
    else
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