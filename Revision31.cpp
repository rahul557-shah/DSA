//Valid Sudoku(Leetcode Q36)
#include <bits/stdc++.h>
using namespace std;
//Time->O(n^2)
//Space->O(3n)
bool isValid(vector<vector<int>> matrix)
{
    vector<unordered_set<int>> row(9);
    vector<unordered_set<int>> col(9);
    vector<unordered_set<int>> subbox(9);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
                continue;
            int num = matrix[i][j];
            if (row[i].count(num))
                return false;
            if (col[j].count(num))
                return false;
            int index = (i / 3) * 3 + j / 3;
            if (subbox[index].count(num))
                return false;
            row[i].insert(num);
            col[j].insert(num);
            subbox[index].insert(num);
        }
    }
    return true;
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
            cin >> matrix[i][j];
    }
    cout << "The Matrix is: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
    if (isValid(matrix))
        cout << "The Sudoku is valid!! " << endl;
    else
        cout << "The Sudoku isnot Valid!!!" << endl;
    return 0;
}