// Sum of Max and Min(Coding Ninja)
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
int sumMaxMin(vector<int> A)
{
    int sum = 0;
    int n = A.size();
    int maxi = INT_MIN, mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, A[i]);
        mini = min(mini, A[i]);
    }
    sum = sum + maxi + mini;
    return sum;
}
// Time->O(nlogn)
// Space->O(1)
vector<int> MaxMin(vector<int> A, int k)
{
    int n = A.size();
    sort(A.begin(), A.end());
    int small = A[k - 1];
    int large = A[n - k];
    vector<int> res;
    res.push_back(large);
    res.push_back(small);
    return res;
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
    cout << "Sum of Max and Min is: " << sumMaxMin(A) << endl;
    int k;
    cout << "Enter value of k: " << endl;
    cin >> k;
    vector<int> res = MaxMin(A, k);
    cout << "Kth max and min is:" << endl;
    printArray(res);
    return 0;
}