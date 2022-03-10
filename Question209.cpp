// Median of row-wise sorted matrix(GFG)
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
int lesserThanMid(vector<int> A, int mid)
{
    int l = 0, h = A.size() - 1;
    while (l <= h)
    {
        int md = (l + h) / 2;
        if (A[md] <= mid)
            l = md + 1;
        else
            h = md - 1;
    }
    return l;
}
// Time->O(32*m*logn)
// Space->O(1)
int medianOfMatrix(vector<vector<int>> &matrix)
{
    int low = INT_MIN, high = INT_MAX;
    int m = matrix.size(), n = matrix[0].size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < m; i++)
            count += lesserThanMid(matrix[i], mid);
        if (count <= (m * n) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
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
    cout << "The Median of the matrix is: " << medianOfMatrix(matrix) << endl;
    return 0;
}