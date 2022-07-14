// Longest String Chain(Leetcode Q.1048)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
bool compare(string &s1, string &s2)
{
    return s1.length() < s2.length();
}
bool checkBoth(string &s1, string &s2)
{
    if (s1.length() != s2.length() + 1)
        return false;
    int first = 0, second = 0;
    while (first < s1.length())
    {
        if (s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
            first++;
    }
    if (first == s1.length() && second == s2.length())
        return true;
    return false;
}
// Time->O(n*n)+O(length of string)
// Space->O(n)
int maximumStringChain(vector<string> &A)
{
    int n = A.size();
    vector<int> dp(n, 1);
    int maxi = 1;
    sort(A.begin(), A.end(), compare);
    for (int i = 1; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (checkBoth(A[i], A[prev]) && 1 + dp[prev] > dp[i])
                dp[i] = 1 + dp[prev];
        }
        if (dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<string> A(n);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The Array is: " << endl;
    printArray(A);
    cout << "Length of Longest String Chain is: " << maximumStringChain(A) << endl;
    return 0;
}