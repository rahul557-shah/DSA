// Nearest Smallest Element(Coding Ninja)
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
    vector<int> nse;
    stk.push(A[n - 1]);
    nse.push_back(-1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!stk.empty() && A[i] <= stk.top())
            stk.pop();
        if (stk.empty())
            nse.push_back(-1);
        else
            nse.push_back(stk.top());
        stk.push(A[i]);
    }
    reverse(nse.begin(), nse.end());
    return nse;
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
    cout << "Next Smaller Element " << endl;
    printArray(ans);
    return 0;
}