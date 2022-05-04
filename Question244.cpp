// Maximum Sum of Non adjacent Elements(GFG,Coding Ninjas)
// House Robber (Leetcode Q.198)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Approach-I(Simple Recurssion)
// Time->O(2^n)
// Space->O(n)
int fun1(int index, vector<int> &A)
{
    if (index == 0)
        return A[index];
    if (index < 0)
        return 0;
    int take = A[index] + fun1(index - 2, A);
    int notTake = 0 + fun1(index - 1, A);
    return max(take, notTake);
}
// Approach-II(Memoization)
// Time->O(n)
// Space->O(n)+O(n)
int fun2(int index, vector<int> &A, vector<int> &dp)
{
    if (index == 0)
        return A[index];
    if (index < 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int take = A[index] + fun2(index - 2, A, dp);
    int notTake = 0 + fun2(index - 1, A, dp);
    return dp[index] = max(take, notTake);
}
int houseRob(vector<int> A)
{
    int n = A.size();
    vector<int> dp(n, -1);
    return fun2(n - 1, A, dp);
}
// Approach-III(Tabulation)
// Time->O(n)
// Space->O(n)
int fun3(vector<int> &A)
{
    int n = A.size();
    vector<int> dp(n, -1);
    dp[0] = A[0];
    for (int i = 1; i < n; i++)
    {
        int take = A[i];
        if (i > 1)
            take = A[i] + dp[i - 2];
        int notTake = 0 + dp[i - 1];
        dp[i] = max(take, notTake);
    }
    return dp[n - 1];
}
// Approach-IV(Space Optimization)
// Time->O(n)
// Space->O(1)
int fun4(vector<int> &A)
{
    int n = A.size();
    int prev1 = A[0], prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int take = A[i];
        if (i > 1)
            take = A[i] + prev2;
        int notTake = 0 + prev1;
        int curr = max(take, notTake);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<int> A(n);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The Array is: " << endl;
    printArray(A);
    cout << "Maximum sum of non adjacent elements is: " << fun4(A) << endl;
    return 0;
}