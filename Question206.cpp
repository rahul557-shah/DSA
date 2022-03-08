// Increasing Triplet Subsequence(Leetcode Q.334)
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
bool increasingTriplet(vector<int> A)
{
    if (A.size() < 3)
        return false;
    int i = INT_MAX, j = INT_MAX;
    for (int k = 0; k < A.size(); k++)
    {
        if (A[k] <= i)
            i = A[k];
        else if (A[k] <= j)
            j = A[k];
        else
            return true;
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<int> A;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << "Array is: " << endl;
    printArray(A);
    if (increasingTriplet(A))
        cout << "Yes it is an increasing triplet subsequence!!" << endl;
    else
        cout << "Not an increasing triplet subsequence!!" << endl;
    return 0;
}