// Rod Cutting Problem(GFG and Coding Ninjas)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Approach-I(Simple Recursion)
// Time-> Greater than O(2^n)
// Space-> Greater than O(n)
int fun1(int index, int N, vector<int> &arr)
{
    if (index == 0)
        return N * arr[0];
    int notTake = 0 + fun1(index - 1, N, arr);
    int take = -1e8;
    int rodLength = index + 1;
    if (N >= rodLength)
        take = arr[index] + fun1(index, N - rodLength, arr);
    return max(take, notTake);
}
// Approach-II(Memoization)
// Time-> O(n*n)
// Space-> O(n*n)+O(n)
int fun2(int index, int N, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index == 0)
        return N * arr[0];
    if (dp[index][N] != -1)
        return dp[index][N];
    int notTake = 0 + fun2(index - 1, N, arr, dp);
    int take = -1e8;
    int rodLength = index + 1;
    if (N >= rodLength)
        take = arr[index] + fun2(index, N - rodLength, arr, dp);
    return dp[index][N] = max(take, notTake);
}
int rodCutting(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return fun1(n - 1, n, arr);
}
// Approach-III(Tabulation)
// Time-> O(n*target)
// Space-> O(n*target)
int fun3(vector<int> &arr, int n)
{
    // int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int N = 0; N <= n; N++)
        dp[0][N] = N * arr[0];
    for (int index = 1; index < n; index++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + dp[index - 1][N];
            int take = -1e9;
            int rodLength = index + 1;
            if (N >= rodLength)
                take = arr[index] + dp[index][N - rodLength];
            dp[index][N] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}
// Approach-IV(Space Optimization)
// Time-> O(n*target)
// Space-> O(target)
int fun4(vector<int> &arr, int n)
{
    // int n = arr.size();
    vector<int> prev(n + 1, 0);
    for (int N = 0; N <= n; N++)
        prev[N] = N * arr[0];
    for (int index = 1; index < n; index++)
    {
        vector<int> curr(n + 1, 0);
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + prev[N];
            int take = -1e9;
            int rodLength = index + 1;
            if (N >= rodLength)
                take = arr[index] + curr[N - rodLength];
            curr[N] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[n];
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the element: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "The Array is: " << endl;
    printArray(arr);
    cout << "Maximum profit by cutting the rod is: " << fun3(arr, n) << endl;
    return 0;
}