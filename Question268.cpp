// Longest Common Substring(GFG and Coding Ninjas)
#include <bits/stdc++.h>
using namespace std;
// Approach-I(Tabulation)
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
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}
// Approach-I(Space Optimization)
// Time-> O(m*n)
// Space-> O(n)
int fun4(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<int> prev(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        vector<int> curr(n + 1, 0);
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
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
    cout << "Length of Longest Common Substring is: " << fun4(s1, s2) << endl;
    return 0;
}