// Best Time to Buy and Sell the Stock - II (Leetcode Q.122)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Approach-I(Simple Recursion)
// Time-> O(2^n)
// Space-> O(n)
int fun1(int index, int buy, vector<int> &A, int n)
{
    if (index == n)
        return 0;
    int profit = 0;
    if (buy == 1)
        profit = max(-A[index] + fun1(index + 1, 0, A, n), 0 + fun1(index + 1, 1, A, n));
    else
        profit = max(A[index] + fun1(index + 1, 1, A, n), 0 + fun1(index + 1, 0, A, n));
    return profit;
}
// Approach-I(Memoization)
// Time-> O(n*2)
// Space-> O(n*2)+O(n)
int fun2(int index, int buy, vector<int> &A, int n, vector<vector<int>> &dp)
{
    if (index == n)
        return 0;
    if (dp[index][buy] != -1)
        return dp[index][buy];
    int profit = 0;
    if (buy == 1)
        profit = max(-A[index] + fun2(index + 1, 0, A, n, dp), 0 + fun2(index + 1, 1, A, n, dp));
    else
        profit = max(A[index] + fun2(index + 1, 1, A, n, dp), 0 + fun2(index + 1, 0, A, n, dp));
    return dp[index][buy] = profit;
}
int buyAndSell(vector<int> &A)
{
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return fun2(0, 1, A, n, dp);
}
// Approach-I(Tabulation)
// Time-> O(n*2)
// Space-> O(n*2)
int fun3(vector<int> &A)
{
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    int profit = 0;
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1)
                profit = max(-A[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
            else
                profit = max(A[index] + dp[index + 1][1], 0 + dp[index + 1][0]);
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}
// Approach-I(Space Optimization)
// Time-> O(n*2)
// Space-> O(4)
int fun4(vector<int> &A)
{
    int n = A.size();
    vector<int> next(2, 0);
    next[0] = 0;
    next[1] = 0;
    int profit = 0;
    for (int index = n - 1; index >= 0; index--)
    {
        vector<int> curr(2, 0);
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1)
                profit = max(-A[index] + next[0], 0 + next[1]);
            else
                profit = max(A[index] + next[1], 0 + next[0]);
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}
// Approach-I(Most Optimal)
// Time-> O(n)
// Space-> O(1)
int fun5(vector<int> &A)
{
    int n = A.size();
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] > A[i - 1])
            profit += A[i] - A[i - 1];
    }
    return profit;
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
    cout << "Maximum Profit is: " << fun5(A) << endl;
    return 0;
}