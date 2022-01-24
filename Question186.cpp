// House Robber(Leetcode Q198)
// Maximum Sum without adjacent(GFG)
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
int maxSumWithoutAdj(vector<int> A)
{
    int n = A.size();
    int inc = A[0], exc = 0, new_exc;
    for (int i = 1; i < n; i++)
    {
        new_exc = max(inc, exc);

        inc = exc + A[i];

        exc = new_exc;
    }
    return max(inc, exc);
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
    cout<<"Maximum Sum without adjacent is: "<<maxSumWithoutAdj(A)<<endl;
    return 0;
}