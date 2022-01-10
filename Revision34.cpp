//Reverse words in a String(Leetcode Q151)
#include <bits/stdc++.h>
using namespace std;
//Time->O(n)
//Space->O(1)
string reverseWord(string S)
{
    string result;
    int i = 0;
    int n = S.length();
    while (i < n)
    {
        while (i < n && S[i] == ' ')
            i++;
        if (i >= n)
            break;
        int j = i + 1;
        while (j < n && S[j] != ' ')
            j++;
        string sub = S.substr(i, j - i);
        if (result.length() == 0)
            result = sub;
        else
            result = sub + " " + result;
        i = j + 1;
    }
    return result;
}
int main()
{
    string S;
    cout << "Enter a string: " << endl;
    getline(cin, S);
    cout << "The String is: " << endl;
    cout << S << endl;
    string result;
    result = reverseWord(S);
    cout << "After Reversing the words : " << endl;
    cout << result << endl;
    return 0;
}