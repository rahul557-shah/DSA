//Reshape the Matrix
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
//Time->O(n^2)
//Space->O(1)
vector<vector<int>> ReshapeMatrix(vector<vector<int>> &matrix, int r, int c)
{
    int row = matrix.size();
    int column = matrix[0].size();
    if ((row * column) != (r * c))
        return matrix;
    vector<vector<int>> res(r, vector<int>(c));
    int row_num = 0;
    int col_num = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            res[row_num][col_num] = matrix[i][j];
            col_num++;
            if (col_num == c)
            {
                col_num = 0;
                row_num++;
            }
        }
    }
    return res;
}
int main()
{
    int m, n;
    cout << "Enter the row and column: " << endl;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements :" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    cout << "The 2D Matrix is: " << endl;
    printArray(matrix, m, n);
    int r, c;
    cout << "Enter the row and column to reshape: " << endl;
    cin >> r >> c;
    vector<vector<int>> res(r, vector<int>(c));
    res = ReshapeMatrix(matrix, r, c);
    cout << "After Reshaping The Matrix is: " << endl;
    printArray(res, r, c);
    return 0;
}