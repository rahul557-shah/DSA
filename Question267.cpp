// Print Longest Common Subsequence(Striver's DP Series)
#include <bits/stdc++.h>
using namespace std;
// Approach-I(Tabulation)
// Time-> O(m*n)+O(m+n)
// Space-> O(m*n)
string fun3(string s1, string s2)
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
    int len = dp[m][n];
    int index = len - 1;
    for (int i = 0; i < len; i++)
        ans += '$';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans[index] = s1[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
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
    cout << "Longest Common Subsequence is: " << fun3(s1, s2) << endl;
    return 0;
}