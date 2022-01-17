// Minimum size Subarray sum(Leetcode Q209)
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
int minSubarray(vector<int> A, int x)
{
    int n = A.size();
    int left = 0, ans = INT_MAX, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        while (sum >= x)
        {
            ans = min(ans, i - left + 1);
            sum -= A[left];
            left++;
        }
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
    int k;
    cout << "Enter the sum: " << endl;
    cin >> k;
    cout << "Minimum Length Subarray with sum grater than equal to " << k << " is: " << minSubarray(A, k) << endl;
    return 0;
}