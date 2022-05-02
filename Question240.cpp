// Climbing Stairs(Leetcode Q.70)
#include <bits/stdc++.h>
using namespace std;
// Approach-I(Simple Recurssion)
// Time->O(2^n)
// Space->O(n)
int climbStairs1(int n)
{
    if (n <= 2)
        return n;
    return climbStairs1(n - 2) + climbStairs1(n - 1);
}
// Approach-II(Memoization)
// Time->O(n)
// Space->O(n)+O(n)
int countSteps(int n, vector<int> &dp)
{
    if (n <= 2)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = countSteps(n - 2, dp) + countSteps(n - 1, dp);
}
int climbStairs2(int n)
{
    vector<int> dp(n + 1, -1);
    return countSteps(n, dp);
}
// Approach-III(Tabulation)
// Time->O(n)
// Space->O(n)
int countNumberOfSteps(int n, vector<int> &dp)
{
    if (n <= 2)
        return n;
    dp[0] = 0, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 2] + dp[i - 1];
    return dp[n];
}
int climbStairs3(int n)
{
    vector<int> dp(n + 1, -1);
    return countNumberOfSteps(n, dp);
}
// Approach-IV(Space Optimization)
// Time->O(n)
// Space->O(1)
int climbStairs4(int n)
{
    if (n <= 2)
        return 2;
    int prev1 = 1, prev2 = 2;
    for (int i = 3; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    cout << "Number of ways to reach the top is: " << climbStairs4(n) << endl;
    return 0;
}