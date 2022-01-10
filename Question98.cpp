//Count and Say problem
#include <bits/stdc++.h>
using namespace std;
string CountAndSay(int n)
{
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";
    string s = "11";
    for (int i = 3; i <= n; i++)
    {
        s = s + '$';
        string t = "";
        int count = 1;
        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] == s[j - 1])
                count++;
            else
            {
                t = t + to_string(count);
                t = t + s[j - 1];
                count = 1;
            }
        }
        s = t;
    }
    return s;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    string res = CountAndSay(n);
    cout << "The Result is: " << res << endl;
    return 0;
}
