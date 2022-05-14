// Triangle(Leetcode Q.120)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> triangle)
{
    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[0].size(); j++)
            cout << triangle[i][j] << " ";
        cout << endl;
    }
}
// Approach-I(Simple Recurssion)
// Time->O(2^(m*m))
// Space->O(m)
int fun1(int i, int j, int m, vector<vector<int>> &triangle)
{
    if (i == m - 1)
        return triangle[i][j];
    int down = triangle[i][j] + fun1(i + 1, j, m, triangle);
    int diagonal = triangle[i][j] + fun1(i + 1, j + 1, m, triangle);
    return min(down, diagonal);
}
// Approach-II(Memoization)
// Time->O(m*m)
// Space->O(m)+O(m*m)
int fun2(int i, int j, int m, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == m - 1)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + fun2(i + 1, j, m, triangle, dp);
    int diagonal = triangle[i][j] + fun2(i + 1, j + 1, m, triangle, dp);
    return dp[i][j] = min(down, diagonal);
}
int minPathTriangle(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    return fun2(0, 0, m, triangle, dp);
}
// Approach-III(Tabulation)
// Time->O(m*m)
// Space->O(m*m)
int fun3(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    for (int j = 0; j < m; j++)
        dp[m - 1][j] = triangle[m - 1][j];
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}
// Approach-IV(Space Optimization)
// Time->O(m*m)
// Space->O(m)
int fun4(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    vector<int> next(m, 0);
    for (int j = 0; j < m; j++)
        next[j] = triangle[m - 1][j];
    for (int i = m - 2; i >= 0; i--)
    {
        vector<int> curr(m, 0);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + next[j];
            int diagonal = triangle[i][j] + next[j + 1];
            curr[j] = min(down, diagonal);
        }
        next = curr;
    }
    return next[0];
}
int main()
{
    int m;
    cout << "Enter the size: " << endl;
    cin >> m;
    vector<vector<int>> triangle(m, vector<int>(m));
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= i; j++)
            cin >> triangle[i][j];
    }
    printArray(triangle);
    cout << "Minimum path of the given triangle is: " << fun4(triangle) << endl;
    return 0;
}