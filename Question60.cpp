// Longest consecutive Subarray
#include <bits/stdc++.h>
using namespace std;
// Time->O(nlogn)
// Space->O(1)
int LongestSubsequence(int A[], int n)
{
    int ans, count;
    ans = count = 0;
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && A[i] == A[i - 1] + 1)
            count++;
        else
            count = 1;
        ans = max(ans, count);
    }
    return ans;
}
// Time->O(N)
// Space->O(N)
int LongestConsecSubSequence(int A[], int n)
{
    int ans = 0;
    unordered_set<int> myset;
    for (int i = 0; i < n; i++)
    {
        myset.insert(A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (!myset.count(A[i] - 1))
        {
            int currentnum = A[i];
            int count = 1;
            while (myset.count(currentnum + 1))
            {
                currentnum += 1;
                count += 1;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    printf("\nLongest Subsequence is: %d", LongestSubsequence(A, n));
    return 0;
}