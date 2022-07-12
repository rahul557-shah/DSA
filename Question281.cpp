// Longest Increasing Subsequnece(Leetcode Q.300)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Approach-I(Simple Recursion)
// Time->O(2^n * 2^n)
// Space->O(n)
int fun1(int index, int prev_ind, int n, vector<int> &A)
{
    if (index == n)
        return 0;
    int notTake = 0 + fun1(index + 1, prev_ind, n, A);
    int take = 0;
    if (prev_ind == -1 || A[index] > A[prev_ind])
        take = 1 + fun1(index + 1, index, n, A);
    return max(take, notTake);
}
// Approach-II(Memoization)
// Time->O(n*n)
// Space->O(n*n)+O(n)
int fun2(int index, int prev_ind, int n, vector<int> &A, vector<vector<int>> &dp)
{
    if (index == n)
        return 0;
    if (dp[index][prev_ind + 1] != -1)
        return dp[index][prev_ind + 1];
    int notTake = 0 + fun2(index + 1, prev_ind, n, A, dp);
    int take = 0;
    if (prev_ind == -1 || A[index] > A[prev_ind])
        take = 1 + fun2(index + 1, index, n, A, dp);
    return dp[index][prev_ind + 1] = max(take, notTake);
}
int LIS(vector<int> &A)
{
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return fun2(0, -1, n, A, dp);
}
// Approach-III(Tabulation)
// Time->O(n*n)
// Space->O(n*n)
int fun3(vector<int> &A)
{
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int prev_ind = index - 1; prev_ind >= -1; prev_ind--)
        {
            int notTake = 0 + dp[index + 1][prev_ind + 1];
            int take = 0;
            if (prev_ind == -1 || A[index] > A[prev_ind])
                take = 1 + dp[index + 1][index + 1];
            dp[index][prev_ind + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}
// Approach-IV(Space Optimization)
// Time->O(n*n)
// Space->O(n*2)
int fun4(vector<int> &A)
{
    int n = A.size();
    vector<int> next(n + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        vector<int> curr(n + 1, 0);
        for (int prev_ind = index - 1; prev_ind >= -1; prev_ind--)
        {
            int notTake = 0 + next[prev_ind + 1];
            int take = 0;
            if (prev_ind == -1 || A[index] > A[prev_ind])
                take = 1 + next[index + 1];
            curr[prev_ind + 1] = max(take, notTake);
        }
        next = curr;
    }
    return next[0];
}
// Approach-V(Algorithmic Approach)
// Time->O(n*n)
// Space->O(n)
int fun5(vector<int> &A)
{
    int n = A.size();
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int index = 0; index < n; index++)
    {
        for (int prev_ind = 0; prev_ind < index; prev_ind++)
        {
            if (A[index] > A[prev_ind])
                dp[index] = max(dp[index], 1 + dp[prev_ind]);
        }
        maxi = max(maxi, dp[index]);
    }
    return maxi;
}
// Most Optimized
//  Approach-V(Binary Search Approach)
//  Time->O(n*logn)
//  Space->O(n)
int fun6(vector<int> &A)
{
    int n = A.size();
    vector<int> temp;
    temp.push_back(A[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (A[i] > temp.back())
        {
            temp.push_back(A[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), A[i]) - temp.begin();
            temp[ind] = A[i];
        }
    }
    return len;
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
    cout << "Length of Longest Increasing Subsequnce is: " << fun5(A) << endl;
    return 0;
}