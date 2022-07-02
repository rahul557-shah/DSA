// Best Time to Buy and Sell the Stock - III (Leetcode Q.123)
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
int fun1(int index, int buy, int count, vector<int> &A, int n)
{
    if (index == n || count == 0)
        return 0;
    int profit = 0;
    if (buy == 1)
        profit = max(-A[index] + fun1(index + 1, 0, count, A, n), 0 + fun1(index + 1, 1, count, A, n));
    else
        profit = max(A[index] + fun1(index + 1, 1, count - 1, A, n), 0 + fun1(index + 1, 0, count, A, n));
    return profit;
}
// Approach-I(Memoization)
// Time-> O(n*2*3)
// Space-> O(n*2*3)+O(n)
int fun2(int index, int buy, int count, vector<int> &A, int n, vector<vector<vector<int>>> dp)
{
    if (index == n || count == 0)
        return 0;
    if (dp[index][buy][count] != -1)
        return dp[index][buy][count];
    int profit = 0;
    if (buy == 1)
        profit = max(-A[index] + fun2(index + 1, 0, count, A, n, dp), 0 + fun2(index + 1, 1, count, A, n, dp));
    else
        profit = max(A[index] + fun2(index + 1, 1, count - 1, A, n, dp), 0 + fun2(index + 1, 0, count, A, n, dp));
    return dp[index][buy][count] = profit;
}
int buyAndSell(vector<int> &A)
{
    int n = A.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return fun2(0, 1, 2, A, n, dp);
}
// Approach-I(Tabulation)
// Time-> O(n*2)
// Space-> O(n*2)
int fun3(vector<int> &A)
{
    int n = A.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    int profit = 0;
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int count = 1; count <= 2; count++)
            {
                if (buy == 1)
                    profit = max(-A[index] + dp[index + 1][0][count], 0 + dp[index + 1][1][count]);
                else
                    profit = max(A[index] + dp[index + 1][1][count - 1], 0 + dp[index + 1][0][count]);
                dp[index][buy][count] = profit;
            }
        }
    }
    return dp[0][1][2];
}
// Approach-I(Space Optimization)
// Time-> O(n*2)
// Space-> O(4)
int fun4(vector<int> &A)
{
    int n = A.size();
    vector<vector<int>> next(2, vector<int>(3, 0));
    int profit = 0;
    for (int index = n - 1; index >= 0; index--)
    {
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int count = 1; count <= 2; count++)
            {
                if (buy == 1)
                    profit = max(-A[index] + next[0][count], 0 + next[1][count]);
                else
                    profit = max(A[index] + next[1][count - 1], 0 + next[0][count]);
                curr[buy][count] = profit;
            }
        }
        next = curr;
    }
    return next[1][2];
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
    cout << "Maximum Profit is: " << fun4(A) << endl;
    return 0;
}