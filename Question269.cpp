// Longest Palindromic Subsequence(Leetcode Q.516)
#include <bits/stdc++.h>
using namespace std;
// Approach-I(Simple Recursion)
// Time-> O(2^m * 2^m)
// Space-> O(m+m)
int fun1(int i, int j, string s1, string s2)
{
    if (i < 0 || j < 0)
        return 0;
    if (s1[i] == s2[j])
        return 1 + fun1(i - 1, j - 1, s1, s2);
    return max(fun1(i - 1, j, s1, s2), fun1(i, j - 1, s1, s2));
}
// Approach-I(Memoization)
// Time-> O(m*m)
// Space-> O(m*m)+O(m+m)
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
int LPS(string s1)
{
    int m = s1.length();
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
    return fun2(m - 1, m - 1, s1, s2, dp);
}
// Approach-III(Tabulation)
// Time-> O(m*m)
// Space-> O(m*m)
int fun3(string s1)
{
    int m = s1.length();
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][m];
}
// Approach-IV(Space Optimization)
// Time-> O(m*m)
// Space-> O(m)
int fun4(string s1)
{
    int m = s1.length();
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    vector<int> prev(m + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        vector<int> curr(m + 1, 0);
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}
int main()
{
    string s1;
    cout << "Enter a string: " << endl;
    cin >> s1;
    cout << "Longest Palindromic Subsequence is: " << fun4(s1) << endl;
}