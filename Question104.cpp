//Count the reversals for bracket matching
#include <bits/stdc++.h>
using namespace std;
int isMatching(char ch1, char ch2)
{
    if (ch1 == '{' && ch2 == '}')
        return 1;
    else
        return 0;
}
int CountInversions(string s)
{
    int c1, c2;
    if (s.length() % 2 == 1)
        return -1;
    else
    {
        stack<char> stk;
        c1 = c2 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '{')
            {
                stk.push(s[i]);
                c2++;
            }
            else if (!stk.empty() && isMatching(stk.top(), s[i]))
            {
                stk.pop();
                c2--;
            }
            else
                c1++;
        }
    }
    if (c1 % 2 == 1)
        c1 = (c1 / 2) + 1;
    else
        c1 = c1 / 2;
    if (c2 % 2 == 1)
        c2 = (c2 / 2) + 1;
    else
        c2 = c2 / 2;
    return (c1 + c2);
}
int main()
{
    string str;
    cout << "Enter the string: " << endl;
    cin >> str;
    cout << "The number of reversals is: " << CountInversions(str) << endl;
    return 0;
}