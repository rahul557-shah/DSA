// Coin Change(Leetcode Q.322)
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
int fun1(int index, int target, vector<int> &arr)
{
    if (index == 0)
    {
        if (target % arr[index] == 0)
            return target / arr[index];
        return 1e9;
    }
    int notTake = 0 + fun1(index - 1, target, arr);
    int take = 1e9;
    if (target >= arr[index])
        take = 1 + fun1(index, target - arr[index], arr);
    return min(take, notTake);
}
// Approach-II(Memoization)
// Time-> O(n*target)
// Space-> O(n*target)+O(n)
int fun2(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target % arr[index] == 0)
            return target / arr[index];
        return 1e9;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notTake = 0 + fun2(index - 1, target, arr, dp);
    int take = 1e9;
    if (target >= arr[index])
        take = 1 + fun2(index, target - arr[index], arr, dp);
    return dp[index][target] = min(take, notTake);
}
int coinChange(vector<int> &arr, int amount)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = fun2(n - 1, amount, arr, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
}
// Approach-III(Tabulation)
// Time-> O(n*target)
// Space-> O(n*target)
int fun3(vector<int> &arr, int amount)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int T = 0; T <= amount; T++)
    {
        if (T % arr[0] == 0)
            dp[0][T] = T / arr[0];
        else
            dp[0][T] = 1e9;
    }
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= amount; target++)
        {
            int notTake = 0 + dp[index - 1][target];
            int take = 1e9;
            if (target >= arr[index])
                take = 1 + dp[index][target - arr[index]];
            dp[index][target] = min(take, notTake);
        }
    }
    return dp[n - 1][amount];
}
// Approach-IV(Space Optimization)
// Time-> O(n*target)
// Space-> O(target)
int fun4(vector<int> &arr, int amount)
{
    int n = arr.size();
    vector<int> prev(amount + 1, 0);
    for (int T = 0; T <= amount; T++)
    {
        if (T % arr[0] == 0)
            prev[T] = T / arr[0];
        else
            prev[T] = 1e9;
    }
    for (int index = 1; index < n; index++)
    {
        vector<int> curr(amount + 1, 0);
        for (int target = 0; target <= amount; target++)
        {
            int notTake = 0 + prev[target];
            int take = 1e9;
            if (target >= arr[index])
                take = 1 + curr[target - arr[index]];
            curr[target] = min(take, notTake);
        }
        prev = curr;
    }
    return prev[amount];
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
    int amount;
    cout << "Enter the amount: " << endl;
    cin >> amount;
    cout << "Minimum number of coins required is: " << fun3(arr, amount) << endl;
    return 0;
}