//Island Perimeter(Leetcode Q463)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> myvec, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << myvec[i][j] << " ";
        cout << "\n";
    }
}
//Time->O(n^2)
//Space->O(1)
int IslandPerimeter(vector<vector<int>> &myvec)
{
    int perimeter = 0;
    for (int i = 0; i < myvec.size(); i++)
    {
        for (int j = 0; j < myvec[0].size(); j++)
        {
            if (myvec[i][j] == 1)
            {
                perimeter += 4;
                if (i > 0 && myvec[i - 1][j] == 1)
                    perimeter -= 2;
                if (j > 0 && myvec[i][j - 1] == 1)
                    perimeter -= 2;
            }
        }
    }
    return perimeter;
}
int main()
{
    int m, n;
    cout << "Enter the row and column: " << endl;
    cin >> m >> n;
    vector<vector<int>> myvec(m, vector<int>(n));
    cout << "Enter the elements :" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> myvec[i][j];
    }
    cout << "The 2D Matrix is: " << endl;
    printArray(myvec, m, n);
    cout << "The Perimeter of the Island is: " << IslandPerimeter(myvec) << endl;
    return 0;
}