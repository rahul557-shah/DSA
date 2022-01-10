//Longest Recurring Subsequnce
#include <bits/stdc++.h>
using namespace std;
//Time->O(n^2)
//Space->O(n^2)
int LongestRecurringSubsequence(string str)
{
    int n = str.length();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str[i - 1] == str[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n][n];
}

int main()
{
    string str1;
    cout << "Enter the string :";
    cin >> str1;
    cout << "Longest Recurring Subsequence is: " << LongestRecurringSubsequence(str1) << endl;
    return 0;
}
