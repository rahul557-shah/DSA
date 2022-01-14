// Longest Valid Parantheses(leetcode Q.32)
#include <bits/stdc++.h>
using namespace std;
void printArray(string A)
{
    for (int i = 0; i < A.length(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(n)
// Space->O(n)
int longestValidPara(string A)
{
    stack<int> stk;
    stk.push(-1);
    int maxi = 0, len;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '(')
            stk.push(i);
        else
        {
            stk.pop();
            if (stk.empty())
                stk.push(i);
            else
            {
                len = i - stk.top();
                maxi = max(maxi, i - stk.top());
            }
        }
    }
    return maxi;
}
int main()
{
    string A;
    cout << "Enter the string: " << endl;
    cin >> A;
    cout << "The String is: " << endl;
    printArray(A);
    cout << "Length of Longest Valid Paranthesis is: " << longestValidPara(A) << endl;
    return 0;
}