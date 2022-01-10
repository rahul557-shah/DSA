//Search a 2D Matrix(Leetcode Q74)
#include <bits/stdc++.h>
using namespace std;
//Time->O(log(m*n))
//Space->O(1)
bool Search2D(vector<vector<int>> matrix, int target)
{
    if (!matrix.size())
        return false;
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0;
    int high = (m * n) - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (matrix[mid / n][mid % n] == target)
            return true;
        else if (matrix[mid / n][mid % n] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
int main()
{
    int m, n;
    cout << "Enter the rows and columns: " << endl;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "The 2D Matrix is: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
    int target;
    cout << "Enter the target " << endl;
    cin >> target;
    if (Search2D(matrix, target))
        cout << "The Element is found!!" << endl;
    else
        cout << "Element not found!!" << endl;
    return 0;
}