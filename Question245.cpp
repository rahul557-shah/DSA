// House Robber II(Leetcode Q.213)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
int fun4(vector<int> &temp)
{
    int n = temp.size();
    int prev1 = temp[0], prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int take = temp[i];
        if (i > 1)
            take = temp[i] + prev2;
        int notTake = 0 + prev1;
        int curr = max(take, notTake);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
// Approach-IV(Space Optimization)
// Time->O(n)
// Space->O(1)
int houseRob(vector<int> &A)
{
    int n = A.size();
    if (n <= 1)
        return A[0];
    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            temp1.push_back(A[i]);
        if (i != 0)
            temp2.push_back(A[i]);
    }
    return max(fun4(temp1), fun4(temp2));
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
    cout << "Maximum sum of non adjacent elements is: " << houseRob(A) << endl;
    return 0;
}