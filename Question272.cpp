// Shortest Common Supersequence(Leetcode Q.1092)
#include <bits/stdc++.h>
using namespace std;
// Approach-I(Tabulation)
// Time-> O(m*n)
// Space-> O(m*n)
string ShortestCommonSupersequence(string s1, string s2)
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
    string ans = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += s1[i - 1];
            i--;
        }
        else
        {
            ans += s2[j - 1];
            j--;
        }
    }
    while (i > 0)
    {
        ans += s1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += s2[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
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
    cout << "Shortest Common Supersequence is: " << ShortestCommonSupersequence(s1, s2) << endl;
    return 0;
}