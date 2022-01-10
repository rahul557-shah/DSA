//Minimum number of swaps to make the bracket balancing
#include <bits/stdc++.h>
using namespace std;
//Time->O(n)
//Space->O(n)
int MinSwaps(string s)
{
    vector<int> v;
    int ans, index, count;
    ans = index = count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
            v.push_back(i);
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            index++;
            count++;
        }
        else
        {
            count--;
            if (count < 0)
            {
                ans += v[index] - i;
                swap(s[i], s[v[index]]);
                count = 1;
                index++;
            }
        }
    }
    return ans;
}
//Time->O(n)
//Space->O(1)
int MinNumOfSwaps(string s)
{
    int open, close, fault, ans;
    open = close = fault = ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ']')
        {
            close++;
            fault = close - open;
        }
        else
        {
            open++;
            if (fault > 0)
            {
                ans += fault;
                fault--;
            }
        }
    }
    return ans;
}
int main()
{
    string str;
    cout << "Enter the string: " << endl;
    cin >> str;
    cout << "Minimum Number of swaps is :" << MinNumOfSwaps(str) << endl;
    return 0;
}