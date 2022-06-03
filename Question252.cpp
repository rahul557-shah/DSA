// Minimum Falling Path Sum(Leetcode Q.931)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}
// Approach-I(Simple Recursion)
//  Time->O(3^m)
//  Space->O(m)
int fun1(int i, int j, int n, vector<vector<int>> &grid)
{
    if (j < 0 || j > n - 1)
        return 1e9;
    if (i == 0)
        return grid[i][j];
    int up = grid[i][j] + fun1(i - 1, j, n, grid);
    int ld = grid[i][j] + fun1(i - 1, j - 1, n, grid);
    int rd = grid[i][j] + fun1(i - 1, j + 1, n, grid);
    return min(up, min(ld, rd));
}
// Approach-I(Memoization)
//  Time->O(m*n)
//  Space->O(m*n)+O(m)
int fun2(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (j < 0 || j > n - 1)
        return 1e9;
    if (i == 0)
        return grid[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + fun2(i - 1, j, n, grid, dp);
    int ld = grid[i][j] + fun2(i - 1, j - 1, n, grid, dp);
    int rd = grid[i][j] + fun2(i - 1, j + 1, n, grid, dp);
    return dp[i][j] = min(up, min(ld, rd));
}
int minimumFallingPath(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int mini = 1e9;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int j = 0; j < n; j++)
        mini = min(mini, fun2(m - 1, j, n, grid, dp));
    return mini;
}
// Approach-I(Tabulation)
//  Time->O(m*n)
//  Space->O(m*n)
int fun3(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int j = 0; j < n; j++)
        dp[0][j] = grid[0][j];
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = grid[i][j] + dp[i - 1][j];
            int ld = grid[i][j];
            if (j - 1 >= 0)
                ld += dp[i - 1][j - 1];
            else
                ld = 1e9;
            int rd = grid[i][j];
            if (j + 1 < n)
                rd += dp[i - 1][j + 1];
            else
                rd = 1e9;
            dp[i][j] = min(up, min(ld, rd));
        }
    }
    int mini = dp[m - 1][0];
    for (int j = 1; j < n; j++)
        mini = min(mini, dp[m - 1][j]);
    return mini;
}
// Approach-I(Space Optimization)
//  Time->O(m*n)
//  Space->O(n)
int fun4(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n, 0);
    for (int j = 0; j < n; j++)
        prev[j] = grid[0][j];
    for (int i = 1; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            int up = grid[i][j] + prev[j];
            int ld = grid[i][j];
            if (j - 1 >= 0)
                ld += prev[j - 1];
            else
                ld = 1e9;
            int rd = grid[i][j];
            if (j + 1 < n)
                rd += prev[j + 1];
            else
                rd = 1e9;
            curr[j] = min(up, min(ld, rd));
        }
        prev = curr;
    }
    int mini = prev[0];
    for (int j = 1; j < n; j++)
        mini = min(mini, prev[j]);
    return mini;
}
int main()
{
    int m, n;
    cout << "Enter the size: " << endl;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    printArray(grid);
    cout << "Minimum falling path sum is: " << fun4(grid) << endl;
    return 0;
}