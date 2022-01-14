// 4 Sum(Leetcode Q.18)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(n^3)
// Space->O(1)
vector<vector<int>> fourSum(vector<int> A, int target)
{
    vector<vector<int>> res;
    int n = A.size();
    sort(A.begin(), A.end());
    vector<int> temp(4, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = target - A[i] - A[j];
            int low = j + 1, high = n - 1;
            while (low < high)
            {
                if (A[low] + A[high] < x)
                    low++;
                else if (A[low] + A[high] > x)
                    high--;
                else
                {
                    temp[0] = (A[i]);
                    temp[1] = (A[j]);
                    temp[2] = (A[low]);
                    temp[3] = (A[high]);
                    res.push_back(temp);

                    while (low < high && A[low] == temp[2])
                        ++low;
                    while (low < high && A[high] == temp[3])
                        --high;
                }
            }
            while (j + 1 < n && A[j] == A[j + 1])
                ++j;
        }
        while (i + 1 < n && A[i] == A[i + 1])
            ++i;
    }
    return res;
}
int main()
{
    vector<int> A;
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << "The Array is: " << endl;
    printArray(A);
    int target;
    cout << "Enter target: " << endl;
    cin >> target;
    vector<vector<int>> result;
    result = fourSum(A, target);
    cout << "Four Sums are: " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}