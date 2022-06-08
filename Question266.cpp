// Longest Common Subsequence(Leetcode Q.1143)
#include <bits/stdc++.h>
using namespace std;
// Approach-I(Simple Recursion)
// Time-> O(2^m * 2^n)
// Space-> O(m+n)
int fun1(int i, int j, string s1, string s2)
{
    if (i < 0 || j < 0)
        return 0;
    if (s1[i] == s2[j])
        return 1 + fun1(i - 1, j - 1, s1, s2);
    return max(fun1(i - 1, j, s1, s2), fun1(i, j - 1, s1, s2));
}
// Approach-II(Memoization)
// Time-> O(m*n)
// Space-> O(m*n)+O(m+n)
int fun2(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + fun2(i - 1, j - 1, s1, s2, dp);
    return dp[i][j] = max(fun2(i - 1, j, s1, s2, dp), fun2(i, j - 1, s1, s2, dp));
}
int lcs(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return fun2(m - 1, n - 1, s1, s2, dp);
}
// Approach-III(Tabulation)
// Time-> O(m*n)
// Space-> O(m*n)
int fun3(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
// Approach-IV(Space Optimization)
// Time-> O(m*n)
// Space-> O(n)
int fun4(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<int> prev(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        vector<int> curr(n + 1, 0);
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[n];
}
int main()
{
    string s1, s2;
    cout << "Enter two strings: " << endl;
    cin >> s1 >> s2;
    cout << "First String is: " << endl;
    cout << s1 << endl;
    cout << "Second String is: " << endl;
    cout << s2 << endl;
    cout << "Length of Longest Common Subsequence is: " << fun4(s1, s2) << endl;
    return 0;
}