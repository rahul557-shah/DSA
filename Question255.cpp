// Partition Equal Subset Sum(Leetcode Q.416)
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
bool fun1(int index, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (index == 0)
        return arr[index] == target;
    bool notTake = fun1(index - 1, target, arr);
    bool take = false;
    if (target >= arr[index])
        take = fun1(index - 1, target - arr[index], arr);
    return take || notTake;
}
// Approach-II(Memoization)
// Time->O(n*k)
// Space->O(n*k)+O(n)
bool fun2(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == 0)
        return arr[index] == target;
    if (dp[index][target] != -1)
        return dp[index][target];
    bool notTake = fun2(index - 1, target, arr, dp);
    bool take = false;
    if (target >= arr[index])
        take = fun2(index - 1, target - arr[index], arr, dp);
    return dp[index][target] = take || notTake;
}
bool subsetSum(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2)
        return false;
    int s1 = sum / 2;
    vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));
    return fun2(n - 1, s1, arr, dp);
}
// Approach-III(Tabulation)
// Time->O(n*k)
// Space->O(n*k)
bool fun3(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2)
        return false;
    int s1 = sum / 2;
    vector<vector<int>> dp(n, vector<int>(s1 + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (s1 >= arr[0])
        dp[0][arr[0]] = true;
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= s1; target++)
        {
            bool notTake = dp[index - 1][target];
            bool take = false;
            if (target >= arr[index])
                take = dp[index - 1][target - arr[index]];
            dp[index][target] = take || notTake;
        }
    }
    return dp[n - 1][s1];
}
// Approach-IV(Space Optimization)
// Time->O(n*k)
// Space->O(k)
bool fun4(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2)
        return false;
    int s1 = sum / 2;
    vector<int> prev(s1 + 1, 0);
    prev[0] = true;
    if (s1 >= arr[0])
        prev[arr[0]] = true;
    for (int index = 1; index < n; index++)
    {
        vector<int> curr(s1 + 1, 0);
        curr[0]=0;
        for (int target = 1; target <= s1; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (target >= arr[index])
                take = prev[target - arr[index]];
            curr[target] = take || notTake;
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
    if (fun4(arr))
        cout << "The Array can be partitioned into two subsets" << endl;
    else
        cout << "Cannot be partitioned" << endl;
    return 0;
}