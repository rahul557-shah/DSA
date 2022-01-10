//Search a 2D Matrix II(Leetcode Q240)
#include <bits/stdc++.h>
using namespace std;
//Time->O(m+n)
//Space->O(1)
bool Search2D(vector<vector<int>> matrix, int target)
{
    if (!matrix.size())
        return false;
    int m = matrix.size();
    int n = matrix[0].size();

    int i = 0;
    int j = n - 1;

    while (i < m && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
            i++;
        else
            j--;
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