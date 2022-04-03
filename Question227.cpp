// Number of Enclaves(Leetcode Q.1020)
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
bool dfs(vector<vector<int>> &grid, int i, int j, int row, int col, int &temp)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
        return false;
    if (grid[i][j] == 0)
        return true;
    if (grid[i][j] == 1)
    {
        grid[i][j] = 0;
        temp++;
    }

    int up = dfs(grid, i - 1, j, row, col, temp);
    int down = dfs(grid, i + 1, j, row, col, temp);
    int left = dfs(grid, i, j - 1, row, col, temp);
    int right = dfs(grid, i, j + 1, row, col, temp);

    return up && down && left && right;
}
// Time->O(m*n)
// Space->O(1)
int closedIsland(vector<vector<int>> grid)
{
    int row = grid.size();
    int col = grid[0].size();
    if (row == 0)
        return 0;
    int res = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                int temp = 0;
                if (dfs(grid, i, j, row, col, temp))
                    res += temp;
            }
        }
    }
    return res;
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
    cout << "Size of Encalve is: " << closedIsland(grid) << endl;
    return 0;
}