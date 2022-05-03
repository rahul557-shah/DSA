// Frog Jump with K distance(DP series)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> heights)
{
    for (int i = 0; i < heights.size(); i++)
        cout << heights[i] << " ";
    cout << endl;
}
// Approach-I(Simple Recurssion)
// Time->O(2^n)
// Space->O(n)
int fun1(int index, vector<int> &heights, int k)
{
    if (index == 0)
        return 0;
    int minJump = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (index - j >= 0)
        {
            int jump = fun1(index - j, heights, k) + abs(heights[index] - heights[index - j]);
            minJump = min(minJump, jump);
        }
    }
    return minJump;
}
// Approach-II(Memoization)
// Time->O(n)
// Space->O(n)+O(n)
int fun2(int index, vector<int> &heights, int k, vector<int> &dp)
{
    if (index == 0)
        return 0;
    int minJump = INT_MAX;
    if (dp[index] != -1)
        return dp[index];
    for (int j = 1; j <= k; j++)
    {
        if (index - j >= 0)
        {
            int jump = fun2(index - j, heights, k, dp) + abs(heights[index] - heights[index - j]);
            dp[index] = min(minJump, jump);
        }
    }
    return dp[index];
}
// Approach-III(Tabulation)
// Time->O(n)
// Space->O(n)
int fun3(int n, vector<int> &heights, int k)
{
    vector<int> dp(n, -1);
    if (n == 0)
        return 0;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minJump = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                dp[i] = min(minJump, jump);
            }
        }
    }
    return dp[n - 1];
}
int frogJump(int n, vector<int> &heights, int k)
{
    // return fun1(n - 1, heights, k);
    vector<int> dp(n, -1);
    return fun2(n - 1, heights, k, dp);
}
int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    vector<int> heights(n);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    cout << "The Array is: " << endl;
    printArray(heights);
    int k;
    cout << "Enter the value of k: " << endl;
    cin >> k;
    cout << "The Minimum number of jump is: " << fun3(n, heights, k) << endl;
    return 0;
}