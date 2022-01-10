//Minimum number of swaps to bring elements less than equal to k together
#include <bits/stdc++.h>
using namespace std;
int MinSwaps(int A[], int n, int k)
{
    int good, bad;
    good = bad = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] <= k)
            good++;
    }
    for (int i = 0; i < good; i++)
    {
        if (A[i] > k)
            bad++;
    }
    int i = 0;
    int j = good;
    int mi = bad;
    while (j < n)
    {
        if (A[i] > k)
            bad--;
        if (A[j] > k)
            bad++;
        mi = min(mi, bad);
        i++;
        j++;
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
    int k;
    cout << "\nEnter the limit: " << endl;
    cin >> k;
    cout << "Minimum Number of swaps is: " << MinSwaps(A, n, k) << endl;
    return 0;
}