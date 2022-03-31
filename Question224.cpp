// Number of islands (Leetcode Q.200)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<char>> grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}
void dfs(vector<vector<char>> &grid, int i, int j, int row, int col)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
        return;
    else if (grid[i][j] != '1')
        return;

    grid[i][j] = '2';

    dfs(grid, i - 1, j, row, col); // Top
    dfs(grid, i + 1, j, row, col); // Bottom
    dfs(grid, i, j - 1, row, col); // Left
    dfs(grid, i, j + 1, row, col); // Right
}
// Time->O(m*n)
// Space->O(1)
int noOfIslands(vector<vector<char>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    if (row == 0)
        return 0;
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j, row, col);
                count += 1;
            }
        }
    }
    return count;
}
int main()
{
    int m, n;
    cout << "Enter the rows and columns: " << endl;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
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
    cout << "Number of Islands is: " << noOfIslands(grid) << endl;
    return 0;
}