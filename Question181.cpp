// Subarray sum equal 'k'
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(n)
// Space->O(n)
int maxSubarraySum(vector<int> A, int k)
{
    int n = A.size();
    unordered_map<int, int> mymap;
    int pre_sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += A[i];
        if (pre_sum == k)
            count++;
        if (mymap.find(pre_sum - k) != mymap.end())
            count += mymap[pre_sum - k];
        mymap[pre_sum]++;
    }
    return count;
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
    printArray(A);
    int k;
    cout << "Enter the sum: " << endl;
    cin >> k;
    cout << "Number of subarray with sum " << k << " is: " << maxSubarraySum(A, k) << endl;
    return 0;
}