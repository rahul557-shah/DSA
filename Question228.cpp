// Shortest Path in Binary Matrix(Leetcode Q.1091)
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
// Time->O(m*n)
// Space->O(n)
int shortestPath(vector<vector<int>> &grid)
{
    if (grid[0][0] == 1)
        return -1;
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    q.push({1, {0, 0}});
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int count = q.front().first;
            q.pop();

            if (x == m - 1 && y == n - 1)
                return count;

            for (int j = 0; j < dir.size(); j++)
            {
                int row = x + dir[j][0];
                int col = y + dir[j][1];
                if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 0)
                {
                    q.push({count + 1, {row, col}});
                    grid[row][col] = 1;
                }
            }
        }
    }
    return -1;
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
    cout << "The Length of Shortest Path is: " << shortestPath(grid) << endl;
    return 0;
}