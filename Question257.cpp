// Count subset with sum 'k'(Coding Ninjas)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Approach-I(Simple Recursion)
// Time->O(2^n)
// Space->O(n)
int fun1(int index, int target, vector<int> &arr)
{
    if (target == 0)
        return 1;
    if (index == 0)
        return arr[index] == target;
    int notTake = fun1(index - 1, target, arr);
    int take = 0;
    if (target >= arr[index])
        take = fun1(index - 1, target - arr[index], arr);
    return take + notTake;
}
// Approach-II(Memoization)
// Time->O(n*k)
// Space->O(n*k)+O(n)
int fun2(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (index == 0)
        return arr[index] == target;
    if (dp[index][target] != -1)
        return dp[index][target];
    int notTake = fun2(index - 1, target, arr, dp);
    int take = 0;
    if (target >= arr[index])
        take = fun2(index - 1, target - arr[index], arr, dp);
    return dp[index][target] = take + notTake;
}
int subsetSum(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return fun2(n - 1, k, arr, dp);
}
// Approach-III(Tabulation)
// Time->O(n*k)
// Space->O(n*k)
int fun3(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (k >= arr[0])
        dp[0][arr[0]] = 1;
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            int notTake = dp[index - 1][target];
            int take = 0;
            if (target >= arr[index])
                take = dp[index - 1][target - arr[index]];
            dp[index][target] = take + notTake;
        }
    }
    return dp[n - 1][k];
}
// Approach-IV(Space Optimization)
// Time->O(n*k)
// Space->O(k)
int fun4(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> prev(k + 1, 0);
    prev[0] = 1;
    if (k >= arr[0])
        prev[arr[0]] = 1;
    for (int index = 1; index < n; index++)
    {
        vector<int> curr(k + 1, 0);
        curr[0] = 1;
        for (int target = 1; target <= k; target++)
        {
            int notTake = prev[target];
            int take = false;
            if (target >= arr[index])
                take = prev[target - arr[index]];
            curr[target] = take + notTake;
        }
        prev = curr;
    }
    return prev[k];
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
    int k;
    cout << "Enter the sum: " << endl;
    cin >> k;
    cout << "Total Subset Sum are: " << fun4(arr, k) << endl;
    return 0;
}