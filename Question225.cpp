// Max Area of Island(Leetcode Q695)
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
void dfs(vector<vector<int>> &grid, int i, int j, int row, int col, int &temp)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
        return;
    else if (grid[i][j] != 1)
        return;
    grid[i][j] = 2;
    temp++;

    dfs(grid, i - 1, j, row, col, temp);
    dfs(grid, i + 1, j, row, col, temp);
    dfs(grid, i, j - 1, row, col, temp);
    dfs(grid, i, j + 1, row, col, temp);
}
// Time->O(m*n)
// Space->O(1)
int maxAreaOfIsland(vector<vector<int>> grid)
{
    int row = grid.size();
    int col = grid[0].size();
    if (row == 0)
        return 0;
    int ans = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int temp = 0;
            if (grid[i][j] == 1)
            {
                dfs(grid, i, j, row, col, temp);
                ans = max(ans, temp);
            }
        }
    }
    return ans;
}
int main()
{
    int m, n;
    cout << "Enter the rows and columns: " << endl;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the element: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << "The Matrix is: " << endl;
    printArray(grid);
    cout << "Maximum size of the island is: " << maxAreaOfIsland(grid) << endl;
    return 0;
}