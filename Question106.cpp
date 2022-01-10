//Word Break Problem
#include <bits/stdc++.h>
using namespace std;
int Compute(string a, vector<string> &b)
{
    unordered_map<string, int> dp;
    int size = a.length();
    if (size == 0)
        return 1;
    if (dp[a] != 0)
        return dp[a];
    for (int i = 1; i <= size; i++)
    {
        int flag = 0;
        string sub = a.substr(0, i);
        for (int j = 0; j < b.size(); j++)
        {
            if (sub.compare(b[j]) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1 && Compute(a.substr(i, size - i), b) == 1)
            return dp[a] = 1;
    }
    return dp[a] = -1;
}
int WordBreak(string A, vector<string> &B)
{
    int x = Compute(A, B);
    if (x == 1)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<string> str1(n);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> str1[i];
    string str;
    cout << "Enter the string: " << endl;
    cin >> str;
    if (WordBreak(str, str1))
        cout << "Yes Present!! " << endl;
    else
        cout << "Not Present!!" << endl;
    return 0;
}
