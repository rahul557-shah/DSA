// Repeated DNA sequences(Leetcode Q.187)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<string> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(n)
// Space->O(n)
vector<string> dnaSequence(string s)
{
    unordered_map<string, int> freq;
    int n = s.length();
    int first = 0, last = 10;
    while (first != n)
    {
        if (s.substr(first, last).length() < 10)
            break;
        freq[s.substr(first, last)]++;
        first++;
    }
    vector<string> ans;
    for (auto itr = freq.begin(); itr != freq.end(); itr++)
    {
        if (itr->second > 1)
            ans.push_back(itr->first);
    }
    return ans;
}
int main()
{
    string s;
    cout << "Enter the string: " << endl;
    cin >> s;
    cout << "String is: " << endl;
    cout << s << endl;
    cout << "Repeated DNA Sequences is: " << endl;
    vector<string> res = dnaSequence(s);
    printArray(res);
    return 0;
}