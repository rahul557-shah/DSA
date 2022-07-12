// Best Time to Buy and Sell the Stock with transaction fee (Leetcode Q.714)
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
int fun1(int index, int buy, vector<int> &A, int n, int fee)
{
    if (index == n)
        return 0;
    int profit = 0;
    if (buy == 1)
        profit = max(-A[index] + fun1(index + 1, 0, A, n, fee), 0 + fun1(index + 1, 1, A, n, fee));
    else
        profit = max(A[index] - fee + fun1(index + 1, 1, A, n, fee), 0 + fun1(index + 1, 0, A, n, fee));
    return profit;
}
// Approach-I(Memoization)
// Time-> O(n*2)
// Space-> O(n*2)+O(n)
int fun2(int index, int buy, vector<int> &A, int n, int fee, vector<vector<int>> &dp)
{
    if (index == n)
        return 0;
    if (dp[index][buy] != -1)
        return dp[index][buy];
    int profit = 0;
    if (buy == 1)
        profit = max(-A[index] + fun2(index + 1, 0, A, n, fee, dp), 0 + fun2(index + 1, 1, A, n, fee, dp));
    else
        profit = max(A[index] - fee + fun2(index + 1, 1, A, n, fee, dp), 0 + fun2(index + 1, 0, A, n, fee, dp));
    return dp[index][buy] = profit;
}
int buyAndSell(vector<int> &A, int fee)
{
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return fun2(0, 1, A, n, fee, dp);
}
// Approach-I(Tabulation)
// Time-> O(n*2)
// Space-> O(n*2)
int fun3(vector<int> &A, int fee)
{
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    int profit = 0;
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1)
                profit = max(-A[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
            else
                profit = max(A[index] - fee + dp[index + 1][1], 0 + dp[index + 1][0]);
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}
// Approach-I(Space Optimization)
// Time-> O(n*2)
// Space-> O(4)
int fun4(vector<int> &A, int fee)
{
    int n = A.size();
    vector<int> next(2, 0);
    int profit = 0;
    for (int index = n - 1; index >= 0; index--)
    {
        vector<int> curr(2, 0);
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 1)
                profit = max(-A[index] + next[0], 0 + next[1]);
            else
                profit = max(A[index] - fee + next[1], 0 + next[0]);
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
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
    int fee;
    cout << "Enter the fee: " << endl;
    cin >> fee;
    cout << "Maximum Profit is: " << fun3(A, fee) << endl;
    return 0;
}