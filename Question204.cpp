// Spiral Matrix (Leetocode Q.54)
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
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(n^2)
// Space->O(1)
vector<int> spiralTraversal(vector<vector<int>> &matrix, int m, int n)
{
    vector<int> ans;
    int row_start = 0, row_end = m - 1;
    int col_start = 0, col_end = n - 1;
    while (row_start <= row_end && col_start <= col_end)
    {
        for (int i = col_start; i <= col_end; i++)
            ans.push_back(matrix[row_start][i]);
        for (int i = row_start + 1; i <= row_end; i++)
            ans.push_back(matrix[i][col_end]);
        if (row_start < row_end)
        {
            for (int i = col_end - 1; i > col_start; i--)
                ans.push_back(matrix[row_end][i]);
            for (int i = row_end; i > row_start; i--)
                ans.push_back(matrix[i][col_start]);
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
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            matrix[i][j] = x;
        }
    }
    cout << "Matrix is: " << endl;
    printMatrix(matrix);
    vector<int> res = spiralTraversal(matrix, m, n);
    cout << "Spiral Traversal is: " << endl;
    printArray(res);
}