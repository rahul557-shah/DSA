//Print all the anagrams together
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> AllAnagrams(vector<string> &S)
{
    map<string, vector<string>> m;
    for (int i = 0; i < S.size(); i++)
    {
        string s = S[i];
        sort(s.begin(), s.end());
        m[s].push_back(S[i]);
    }
    int index = 0;
    vector<vector<string>> ans(m.size());
    for (auto x : m)
    {
        auto v = x.second;
        for (int i = 0; i < v.size(); i++)
            ans[index].push_back(v[i]);
        index++;
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<string> str1(n);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> str1[i];
    vector<vector<string>> res = AllAnagrams(str1);
    sort(res.begin(), res.end());
    cout << "The Anagrams are: " << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << endl;
    }
    return 0;
}
