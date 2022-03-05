// Pascal's Traingle - II (Leetcode Q.119)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(k^2)
// Space->O(k)
vector<int> extractKthRow(int row)
{
    vector<int> res(row + 1, 1);
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j > 0; j--)
            res[j] += res[j - 1];
    }
    return res;
}
// Time->O(k^2)
// Space->O(k^2)
vector<int> extractRow(int row)
{
    vector<vector<int>> res(row + 1);
    for (int i = 0; i <= row; i++)
    {
        res[i].resize(i + 1);
        res[i][0] = res[i][i] = 1;
        for (int j = 1; j < i; j++)
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }
    return res[row];
}
int main()
{
    int row;
    cout << "Enter the row to be extrated: " << endl;
    cin >> row;
    vector<int> ans = extractRow(row);
    cout << "The Kth Row of Pascal's Triangle is: " << endl;
    printArray(ans);
}