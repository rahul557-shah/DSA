//Valid Anagram(Leetcode Q242)
#include <bits/stdc++.h>
using namespace std;
//Time->O(n)
//Space->O(n)
bool isValid(string S1, string S2)
{
    unordered_map<int, int> m;
    if (S1.length() != S2.length())
        return false;
    for (int i = 0; i < S1.length(); i++)
    {
        m[S1[i] - 97]++;
    }
    for (int i = 0; i < S2.length(); i++)
    {
        if (m[S2[i] - 97] >= 1)
        {
            m[S2[i] - 97]--;
            if (m[S2[i] - 97] < 0)
                return false;
        }
        else if (m[S2[i] - 97] == 0)
            return false;
    }
    return true;
}
int main()
{
    string S1, S2;
    cout << "Enter two strings: " << endl;
    cin >> S1 >> S2;
    cout << "The First String is: " << S1 << endl;
    cout << "The Second String is: " << S2 << endl;
    if (isValid(S1, S2))
        cout << "They are Anagram!!" << endl;
    else
        cout << "Not Anagram!!" << endl;
    return 0;
}