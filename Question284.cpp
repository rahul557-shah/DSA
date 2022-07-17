// Number of Longest Increasing Subset(Leetcode Q.673)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Time->O(n*n)+O(n)
// Space->O(n*2)
int noOfLIS(vector<int> &A)
{
    int n = A.size();
    vector<int> dp(n, 1), count(n, 1);
    int maxi = 1;
    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (A[i] > A[prev] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                count[i] = count[prev];
            }
            else if (A[i] > A[prev] && 1 + dp[prev] == dp[i])
                count[i] += count[prev];
        }
        maxi = max(maxi, dp[i]);
    }
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            num += count[i];
    }
    return num;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<int> A(n);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The Array is: " << endl;
    printArray(A);
    cout << "Number of Longest Increasing Subsequence is: " << noOfLIS(A) << endl;
    return 0;
}