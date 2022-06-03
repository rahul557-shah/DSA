// Cherry Pickup (Letcode Q.1463)
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
//  Time->O(3^m*3^m)
//  Space->O(m)
int fun1(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid)
{
    if ((j1 < 0 || j1 > n - 1) || (j2 < 0 || j2 > n - 1))
        return -1e9;
    if (i == m - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    int maxi = -1e9;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += fun1(i + 1, j1 + dj1, j2 + dj2, m, n, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}
// Approach-II(Memoization)
//  Time->O(m*n*n)*9
//  Space->O(m*n*n)+O(m)
int fun2(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if ((j1 < 0 || j1 > n - 1) || (j2 < 0 || j2 > n - 1))
        return -1e9;
    if (i == m - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = -1e9;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];
            value += fun2(i + 1, j1 + dj1, j2 + dj2, m, n, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    return fun2(0, 0, n - 1, m, n, grid, dp);
}
// Approach-III(Tabulation)
//  Time->O(m*n*n)*9
//  Space->O(m*n*n)
int fun3(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
    for (int j1 = 0; j1 < n; j1++)
    {
        for (int j2 = 0; j2 < n; j2++)
        {
            if (j1 == j2)
                dp[m - 1][j1][j2] = grid[m - 1][j1];
            else
                dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
        }
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                int maxi = -1e9;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if ((j1 + dj1 < 0 || j1 + dj1 > n - 1) || (j2 + dj2 < 0 || j2 + dj2 > n - 1))
                            value = -1e9;
                        else
                            value += dp[i + 1][j1 + dj1][j2 + dj2];
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][n - 1];
}
// Approach-III(Space Optimization)
//  Time->O(m*n*n)*9
//  Space->O(n*n)
int fun4(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> next(n, vector<int>(n, 0));
    for (int j1 = 0; j1 < n; j1++)
    {
        for (int j2 = 0; j2 < n; j2++)
        {
            if (j1 == j2)
                next[j1][j2] = grid[m - 1][j1];
            else
                next[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
        }
    }
    for (int i = m - 2; i >= 0; i--)
    {
        vector<vector<int>> curr(n, vector<int>(n, 0));
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                int maxi = -1e9;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];
                        if ((j1 + dj1 < 0 || j1 + dj1 > n - 1) || (j2 + dj2 < 0 || j2 + dj2 > n - 1))
                            value = -1e9;
                        else
                            value += next[j1 + dj1][j2 + dj2];
                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        next = curr;
    }
    return next[0][n - 1];
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
    cout << "Maximum sum of cherry is: " << fun4(grid) << endl;
    return 0;
}