// Spiral Matrix II (Leetocode Q.59)
#include <bits/stdc++.h>
using namespace std;
void printMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
// Time->O(n^2)
// Space->O(1)
vector<vector<int>> spiralMatrix(int m, int n)
{
    vector<vector<int>> ans(m, vector<int>(n));
    int row_start = 0, row_end = m - 1;
    int col_start = 0, col_end = n - 1;
    int val = 1;
    while (row_start <= row_end && col_start <= col_end)
    {
        for (int i = col_start; i <= col_end; i++)
            ans[row_start][i] = val++;
        for (int i = row_start + 1; i <= row_end; i++)
            ans[i][col_end] = val++;
        if (row_start < row_end)
        {
            for (int i = col_end - 1; i > col_start; i--)
                ans[row_end][i] = val++;
            for (int i = row_end; i > row_start; i--)
                ans[i][col_start] = val++;
        }
        row_start++;
        row_end--;
        col_start++;
        col_end--;
    }
    return ans;
}
int main()
{
    int m, n;
    cout << "Enter the rows and columns: " << endl;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    matrix = spiralMatrix(m, n);
    cout << "Matrix is: " << endl;
    printMatrix(matrix);
    return 0;
}