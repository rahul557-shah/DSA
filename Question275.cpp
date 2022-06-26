// Wildcard Matching(Leetcode Q.44)
#include <bits/stdc++.h>
using namespace std;
// Approach-I(Simple Recursion)
// Time-> O(2^m * 2^n)
// Space-> O(m+n)
bool fun1(int i, int j, string pattern, string str)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
    {
        for (int k = 0; k <= i; k++)
        {
            if (pattern[k] != '*')
                return false;
        }
        return true;
    }
    if (pattern[i] == str[j] || pattern[i] == '?')
        return fun1(i - 1, j - 1, pattern, str);
    if (pattern[i] == '*')
        return fun1(i - 1, j, pattern, str) || fun1(i, j - 1, pattern, str);
    return false;
}
// Approach-II(Memoization)
// Time-> O(m*n)
// Space-> O(m*n)+O(m+n)
bool fun2(int i, int j, string pattern, string str, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
    {
        for (int k = 0; k <= i; k++)
        {
            if (pattern[k] != '*')
                return false;
        }
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (pattern[i] == str[j] || pattern[i] == '?')
        return dp[i][j] = fun2(i - 1, j - 1, pattern, str, dp);
    if (pattern[i] == '*')
        return dp[i][j] = fun2(i - 1, j, pattern, str, dp) || fun2(i, j - 1, pattern, str, dp);
    return dp[i][j] = false;
}
int wildcardMatching(string pattern, string str)
{
    int m = pattern.length();
    int n = str.length();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return fun2(m - 1, n - 1, pattern, str, dp);
}
// Approach-III(Tabulation)
// Time-> O(m*n)
// Space-> O(m*n)
bool fun3(string pattern, string str)
{
    int m = pattern.length();
    int n = str.length();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= n; j++)
        dp[0][j] = false;
    for (int i = 1; i <= m; i++)
    {
        bool flag = true;
        for (int k = 1; k <= i; k++)
        {
            if (pattern[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (pattern[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    return dp[m][n];
}
// Approach-IV(Space Optimization)
// Time-> O(m*n)
// Space-> O(n)
bool fun4(string pattern, string str)
{
    int m = pattern.length();
    int n = str.length();
    vector<bool> prev(n + 1, false);
    prev[0] = true;
    for (int j = 1; j <= n; j++)
        prev[j] = false;
    for (int i = 1; i <= m; i++)
    {
        vector<bool> curr(n + 1, false);
        bool flag = true;
        for (int k = 1; k <= i; k++)
        {
            if (pattern[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        curr[0] = flag;
        for (int j = 1; j <= n; j++)
        {
            if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
                curr[j] = prev[j - 1];
            else if (pattern[i - 1] == '*')
                curr[j] = prev[j] || curr[j - 1];
            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[n];
}
int main()
{
    string pattern, str;
    cout << "Enter a pattern and a string: " << endl;
    cin >> pattern >> str;
    cout << "First String is: " << endl;
    cout << pattern << endl;
    cout << "Second String is: " << endl;
    cout << str << endl;
    if (fun4(pattern, str))
        cout << "The string matches with the pattern!!" << endl;
    else
        cout << "No match!!" << endl;
    return 0;
}