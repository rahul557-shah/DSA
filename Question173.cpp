// Maximum Consecutive Ones(Leetcode 485)
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
int maxConsecutiveOnes(vector<int> A)
{
    int n = A.size();
    int count = 0, maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 1)
            count++;
        else
            count = 0;
        maxCount = max(maxCount, count);
    }
    return maxCount;
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
    cout << "The Maximum Consecutive Ones is: " << maxConsecutiveOnes(A) << endl;
    return 0;
}