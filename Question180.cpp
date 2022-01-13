// Maximum Subarray with 0 sum
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(nlogn)
// Space->O(n)
int maxSubarray(vector<int> A)
{
    int n = A.size();
    unordered_map<int, int> mymap;
    int pre_sum = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += A[i];
        if (pre_sum == 0)
            maxi = i + 1;
        else if (mymap.find(pre_sum) != mymap.end())
            maxi = max(maxi, i - mymap[pre_sum]);
        else
            mymap[pre_sum] = i;
    }
    return maxi;
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
    cout << "Maximum Length of subarray with 0 sum is: " << maxSubarray(A) << endl;
    return 0;
}