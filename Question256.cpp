// Partition set into two subsets with minimum absolute sum difference(GFG and Coding Ninjas)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Approach-I(Tabulation)
// Time->O(n*k)
// Space->O(n*k)
bool fun3(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (sum >= arr[0])
        dp[0][arr[0]] = true;
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= sum; target++)
        {
            bool notTake = dp[index - 1][target];
            bool take = false;
            if (target >= arr[index])
                take = dp[index - 1][target - arr[index]];
            dp[index][target] = take || notTake;
        }
    }
    int mini = 1e9;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int s1 = i;
            int s2 = sum - s1;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
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
    cout << "The minimum differences between two partition sum is: " << fun3(arr) << endl;
    return 0;
}