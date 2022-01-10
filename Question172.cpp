// Next Greater Element(Leetcode Q503)
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
vector<int> NextGreater(vector<int> A)
{
    int n = A.size();
    stack<int> stk;
    vector<int> nge;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!stk.empty() && A[i % n] >= stk.top())
            stk.pop();
        if (i < n)
        {
            if (stk.empty())
                nge.push_back(-1);
            else
                nge.push_back(stk.top());
        }
        stk.push(A[i % n]);
    }
    reverse(nge.begin(), nge.end());
    return nge;
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
    vector<int> ans = NextGreater(A);
    cout << "Next Greater " << endl;
    printArray(ans);
    return 0;
}