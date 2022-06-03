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
int fun1(int i, int j, int n, vector<vector<int>> &grid)
{
    if (j < 0 || j > n - 1)
        return INT_MAX;
    if (i == 0)
        return grid[i][j];
}
int minimumFallingPath(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int mini = INT_MAX;
    for (int j = 0; j < n; j++)
        mini = min(mini, fun1(m - 1, j, n, grid));
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
    // cout << "Minimum path of the given grid is: " << fun4(grid) << endl;
    return 0;
}