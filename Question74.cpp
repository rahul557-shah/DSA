//Maximum Profit By Buying and Selling the stock atmost twice
#include <bits/stdc++.h>
using namespace std;
//Time->O(n)
//Space->O(n)
int MaxProfit(int A[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 0;
    int ma = A[n - 1];
    int mi = A[0];
    for (int i = n - 2; i > 0; i--)
    {
        if (A[i] > ma)
            ma = A[i];
        dp[i] = max(dp[i + 1], ma - A[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (A[i] < mi)
            mi = A[i];
        dp[i] = max(dp[i - 1], dp[i] + (A[i] - mi));
    }
    return dp[n - 1];
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
    cout << "\nMaximum Profit is " << MaxProfit(A, n) << endl;
    return 0;
}
