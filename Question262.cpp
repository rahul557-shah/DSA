// Target Sum (Leetcode Q.494)
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
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
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
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notTake = fun2(index - 1, target, arr, dp);
    int take = 0;
    if (target >= arr[index])
        take = fun2(index - 1, target - arr[index], arr, dp);
    return dp[index][target] = take + notTake;
}
int targetSum(vector<int> &arr, int target)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum - target < 0 || (sum - target) % 2 == 1)
        return 0;
    int s1 = (sum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));
    return fun2(n - 1, s1, arr, dp);
}
// Approach-III(Tabulation)
// Time->O(n*k)
// Space->O(n*k)
int fun3(vector<int> &arr, int target)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum - target < 0 || (sum - target) % 2 == 1)
        return 0;
    int s1 = (sum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(s1 + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] != 0 && s1 >= arr[0])
        dp[0][arr[0]] = 1;
    for (int index = 1; index < n; index++)
    {
        for (int t = 1; t <= s1; t++)
        {
            int notTake = dp[index - 1][t];
            int take = 0;
            if (t >= arr[index])
                take = dp[index - 1][t - arr[index]];
            dp[index][t] = take + notTake;
        }
    }
    return dp[n - 1][s1];
}
// Approach-IV(Space Optimization)
// Time->O(n*k)
// Space->O(k)
int fun4(vector<int> &arr, int target)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum - target < 0 || (sum - target) % 2 == 1)
        return 0;
    int s1 = (sum - target) / 2;
    vector<int> prev(s1 + 1, 0);
    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if (arr[0] != 0 && arr[0] <= s1)
        prev[arr[0]] = 1;
    for (int index = 1; index < n; index++)
    {
        vector<int> curr(s1 + 1, 0);
        for (int t = 0; t <= s1; t++)
        {
            int notTake = prev[t];
            int take = false;
            if (t >= arr[index])
                take = prev[t - arr[index]];
            curr[t] = take + notTake;
        }
        prev = curr;
    }
    return prev[s1];
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
    int target;
    cout << "Enter the difference: " << endl;
    cin >> target;
    cout << "Total Subset with given difference are: " << targetSum(arr, target) << endl;
    return 0;
}