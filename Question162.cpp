// 3 Sum Problem(Leetcode Q15)
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    cout << "The Array is: " << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(n^2)
// Space->O(1)
vector<vector<int>> threeSum(int A[], int n)
{
    vector<vector<int>> ans;
    sort(A, A + n);
    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 || (i > 0 && A[i] != A[i - 1]))
        {
            int low = i + 1, high = n - 1, sum = 0 - A[i];

            while (low < high)
            {
                if (A[low] + A[high] == sum)
                {
                    vector<int> temp;
                    temp.push_back(A[i]);
                    temp.push_back(A[low]);
                    temp.push_back(A[high]);
                    ans.push_back(temp);

                    while (low < high && A[low] == A[low + 1])
                        low++;
                    while (low < high && A[high] == A[high - 1])
                        high--;
                    low++;
                    high--;
                }
                else if (A[low] + A[high] < sum)
                    low++;
                else
                    high--;
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size :" << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    printArray(A, n);
    vector<vector<int>> ans;
    ans = threeSum(A, n);
    cout << "The Three Sum are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}