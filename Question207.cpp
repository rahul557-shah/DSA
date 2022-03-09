// Longest Palindrome(Leetcode Q.409)
#include <bits/stdc++.h>
using namespace std;
// Time->O(n)
// Space->O(n)
int longestPalindrome(string s)
{
    unordered_map<char, int> mymap;
    int result = 0;
    bool odd_count = false;
    for (int i = 0; i < s.length(); i++)
        mymap[s[i]]++;
    for (auto x : mymap)
    {
        if (x.second % 2 == 0)
            result += x.second;
        else
        {
            odd_count = true;
            result += x.second - 1;
        }
    }
    if (odd_count)
        result++;
    return result;
}
int main()
{
    string s;
    cout << "Enter the string: " << endl;
    cin >> s;
    cout << "String is: " << endl;
    cout << s << endl;
    cout << "Longest Palindrome size is: " << longestPalindrome(s) << endl;
    return 0;
}