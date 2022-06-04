// Sliding Window Maximum(Leetcode Q.239)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Approach-I(Brutt Force)
// Time->O(n*k)
// Space->O(1)
vector<int> slidingWindow(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < n - 2; i++)
    {
        int maxi = arr[i];
        for (int j = i + 1; j < i + k; j++)
            maxi = max(maxi, arr[j]);
        ans.push_back(maxi);
    }
    return ans;
}
// Approach-I(Optimal Approach)
// Time->O(n)
// Space->O(n)
vector<int> slidingWindowMax(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the element: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "The Array is: " << endl;
    printArray(arr);
    int k;
    cout << "Enter the value of K: " << endl;
    cin >> k;
    vector<int> res = slidingWindowMax(arr, k);
    cout << "The Maximum elements is: " << endl;
    printArray(res);
    return 0;
}