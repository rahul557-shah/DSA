// Grid Unique Paths(Leetcode Q.62)
#include <bits/stdc++.h>
using namespace std;
// Approach-I(Simple Recurssion)
// Time->O(2^(m*n))
// Space->O((m-1)+(n-1))
int fun1(int i, int j)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = fun1(i - 1, j);
    int left = fun1(i, j - 1);
    return up + left;
}
// Approach-II(Memoization)
// Time->O(m*n)
// Space->O((m-1)+(n-1))+O(m*n)
int fun2(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = fun2(i - 1, j, dp);
    int left = fun2(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return fun2(m - 1, n - 1, dp);
}
// Approach-III(Tabulation)
// Time->O(m*n)
// Space->O(m*n)
int fun3(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}
// Approach-IV(Space Optimization)
// Time->O(m*n)
// Space->O(n)
int fun4(int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {

            if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}
int main()
{
    int m, n;
    cout << "Enter the number of rows and columns: " << endl;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Number of unique paths is: " << fun4(m, n) << endl;
    return 0;
}