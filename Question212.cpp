// Minimum remove to make valid paranthese(Leetcode Q1249)
#include <bits/stdc++.h>
using namespace std;
// Time->O(n)
// Space->O(n)
string minRemoveForValidParantheses(string s)
{
    int n = s.length();
    int i = 0, count = 0;
    stack<int> stk;
    while (i < n)
    {
        if (s[i] == '(')
        {
            stk.push(i);
            count++;
        }
        else if (s[i] == ')')
        {
            if (count > 0)
            {
                stk.pop();
                count--;
            }
            else
                stk.push(i);
        }
        i++;
    }
    int m = stk.size();
    while (m--)
    {
        int temp = stk.top();
        s.erase(temp, 1);
        stk.pop();
    }
    return s;
}
int main()
{
    string s;
    cout << "Enter a string: " << endl;
    cin >> s;
    cout << "String is: " << s << endl;
    string res = minRemoveForValidParantheses(s);
    cout << "After Removing Invalid Parantheses: " << res << endl;
    return 0;
}