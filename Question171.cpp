// Next Greater Element(GFG)
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
    vector<int> res;
    int n = A.size();
    stack<int> stk;
    res.push_back(-1);
    stk.push(A[n - 1]);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && A[i] >= stk.top())
            stk.pop();
        if (stk.empty())
            res.push_back(-1);
        else
            res.push_back(stk.top());
        stk.push(A[i]);
    }
    reverse(res.begin(), res.end());
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
    vector<int> ans = NextGreater(A);
    cout << "Next Greater " << endl;
    printArray(ans);
    return 0;
}