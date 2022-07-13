// Longest Divisible Subset(Leetcode Q.368)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Time->O(n*n)
// Space->O(n*2)
vector<int> LDS(vector<int> &A)
{
    int n = A.size();
    sort(A.begin(), A.end());
    vector<int> dp(n, 1), hash(n);
    int lastIndex = 0, maxi = 1;
    for (int i = 1; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (A[i] % A[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (maxi < dp[i])
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(A[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(A[lastIndex]);
    }
    return temp;
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
    vector<int> res = LDS(A);
    cout << "Longest Divisible Subset is: " << endl;
    printArray(res);
    return 0;
}