// Minimum Path Sum(LeetcodeQ.64)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < 3; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}
// Approach-I(Simple Recurssion)
// Time->O(2^(m*n))
// Space->O((m-1)+(n-1))
int fun1(int i, int j, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    int up = grid[i][j] + fun1(i - 1, j, grid);
    int left = grid[i][j] + fun1(i, j - 1, grid);
    return min(up, left);
}
// Approach-II(Memoization)
// Time->O(m*n)
// Space->O((m-1)+(n-1))+O(m*n)
int fun2(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + fun2(i - 1, j, grid, dp);
    int left = grid[i][j] + fun2(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}
int minimumPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return fun2(m - 1, n - 1, grid, dp);
}
// Approach-III(Tabulation)
// Time->O(m*n)
// Space->O(m*n)
int fun3(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;
                int left = grid[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[m - 1][n - 1];
}
// Approach-IV(Space Optimization)
// Time->O(m*n)
// Space->O(n)
int fun4(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 10e4;
                int left = grid[i][j];
                if (j > 0)
                    left += curr[j - 1];
                else
                    left += 10e4;
                curr[j]=min(up,left);
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
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    cout << "The Grid is: " << endl;
    printArray(grid);
    cout << "Number of unique paths is: " << fun4(grid) << endl;
    return 0;
}