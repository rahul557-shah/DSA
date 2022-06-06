// Unbounded Knapsack Problem(GFG and Coding Ninjas)
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
int fun1(int index, int W, vector<int> &wt, vector<int> &value)
{
    if (index == 0)
        return (W / wt[0]) * value[0];
    int notTake = 0 + fun1(index - 1, W, wt, value);
    int take = -1e8;
    if (W >= wt[index])
        take = value[index] + fun1(index, W - wt[index], wt, value);
    return max(take, notTake);
}
// Approach-II(Memoization)
// Time->O(n*W)
// Space->O(n*W)+O(n)
int fun2(int index, int W, vector<int> &wt, vector<int> &value, vector<vector<int>> &dp)
{
    if (index == 0)
        return (W / wt[0]) * value[0];
    if (dp[index][W] != -1)
        return dp[index][W];
    int notTake = 0 + fun1(index - 1, W, wt, value);
    int take = -1e8;
    if (W >= wt[index])
        take = value[index] + fun1(index, W - wt[index], wt, value);
    return dp[index][W] = max(take, notTake);
}
int knapsack(int W, int n, vector<int> wt, vector<int> value)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return fun2(n - 1, W, wt, value, dp);
}
// Approach-III(Tabulation)
// Time->O(n*W)
// Space->O(n*W)
int fun3(int W, int n, vector<int> wt, vector<int> value)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int T = wt[0]; T <= W; T++)
        dp[0][T] = (T / wt[0]) * value[0];
    for (int index = 1; index < n; index++)
    {
        for (int weight = 1; weight <= W; weight++)
        {
            int notTake = 0 + dp[index - 1][weight];
            int take = -1e8;
            if (weight >= wt[index])
                take = value[index] + dp[index][weight - wt[index]];
            dp[index][weight] = max(take, notTake);
        }
    }
    return dp[n - 1][W];
}
// Approach-IV(Space Optimization)
// Time->O(n*W)
// Space->O(W)+O(W)
int fun4(int W, int n, vector<int> wt, vector<int> value)
{
    vector<int> prev(W + 1, 0);
    for (int T = wt[0]; T <= W; T++)
        prev[T] = (T / wt[0]) * value[0];
    for (int index = 1; index < n; index++)
    {
        vector<int> curr(W + 1, 0);
        for (int weight = 1; weight <= W; weight++)
        {
            int notTake = 0 + prev[weight];
            int take = -1e8;
            if (weight >= wt[index])
                take = value[index] + curr[weight - wt[index]];
            curr[weight] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[W];
}
// Approach-V(Space Optimization to Single Array)
// Time->O(n*W)
// Space->O(W)
int fun5(int W, int n, vector<int> wt, vector<int> value)
{
    vector<int> prev(W + 1, 0);
    for (int T = wt[0]; T <= W; T++)
        prev[T] = (T / wt[0]) * value[0];
    for (int index = 1; index < n; index++)
    {
        for (int weight = 0; weight <=W; weight++)
        {
            int notTake = 0 + prev[weight];
            int take = -1e8;
            if (weight >= wt[index])
                take = value[index] + prev[weight - wt[index]];
            prev[weight] = max(take, notTake);
        }
    }
    return prev[W];
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<int> wt(n), value(n);
    cout << "Enter the weights and values: " << endl;
    for (int i = 0; i < n; i++)
        cin >> wt[i] >> value[i];
    cout << "The weight Array is: " << endl;
    printArray(wt);
    cout << "The value array is: " << endl;
    printArray(value);
    int W;
    cout << "Enter the max weight: " << endl;
    cin >> W;
    cout << "Maximum profit is: " << fun5(W, n, wt, value) << endl;
    return 0;
}