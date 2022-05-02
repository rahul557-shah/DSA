// Frog Jump(Coding Ninjas)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> heights)
{
    for (int i = 0; i < heights.size(); i++)
        cout << heights[i] << " ";
    cout << endl;
}
// Approach-I(Simple Recurssion)
// Time->O(2^n)
// Space->O(n)
int fun1(int index, vector<int> &heights)
{
    if (index == 0)
        return 0;
    int left = fun1(index - 1, heights) + abs(heights[index] - heights[index - 1]);

    int right = INT_MAX;
    if (index > 1)
        right = fun1(index - 2, heights) + abs(heights[index] - heights[index - 2]);
    return min(left, right);
}
// Approach-II(Memoization)
// Time->O(n)
// Space->O(n)+O(n)
int fun2(int index, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int left = fun2(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);

    int right = INT_MAX;
    if (index > 1)
        right = fun2(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
    return dp[index] = min(left, right);
}
// Approach-III(Tabulation)
// Time->O(n)
// Space->O(n)
int fun3(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    if (n == 0)
        return 0;
    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}
// Approach-IV(Space Optimization)
// Time->O(n)
// Space->O(1)
int fun4(int n, vector<int> &heights)
{
    int prev1 = 0, prev2 = 0;
    if (n == 0)
        return 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev1 + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(heights[i] - heights[i - 2]);
        prev2 = prev1;
        prev1 = min(left, right);
    }
    return prev1;
}
int frogJump(int n, vector<int> &heights)
{
    // return fun1(n - 1, heights);
    vector<int> dp(n, -1);
    return fun2(n - 1, heights, dp);
}
int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    vector<int> heights(n);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    cout << "The Array is: " << endl;
    printArray(heights);
    cout << "The Minimum number of jump is: " << fun4(n, heights) << endl;
    return 0;
}