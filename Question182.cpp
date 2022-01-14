// Maximum Consecutive Ones III (Leetcode Q.1004)
// Sliding Window Approach
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(n)
// Space->O(1)
int maxConsecutiveOnes(vector<int> A, int k)
{
    int n = A.size();
    int i = 0, j = 0;
    int ans = 0, zeroCount = 0;
    while (j < n)
    {
        if (A[j] == 0)
            zeroCount++;
        while (zeroCount > k)
        {
            if (A[i] == 0)
                zeroCount--;
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}
int main()
{
    vector<int> A;
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << "The Array is: " << endl;
    printArray(A);
    int k;
    cout << "Enter value of K: " << endl;
    cin >> k;
    cout << "Maximum Consecutive Ones after adding " << k << " 0's: " << maxConsecutiveOnes(A, k) << endl;
    return 0;
}