// Partition Labels(Leetcode Q.763)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(n)
// Space->O(1)
vector<int> partitionLabel(string s)
{
    vector<int> last_idx(26, 0);
    for (int i = 0; i < s.length(); i++)
        last_idx[s[i] - 'a'] = i;
    int start = 0, end = 0;
    vector<int> ans;
    for (int i = 0; i < s.length(); i++)
    {
        end = max(end, last_idx[s[i] - 'a']);
        if (i == end)
        {
            ans.push_back(i - start + 1);
            start = i + 1;
        }
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
    vector<int> res = partitionLabel(s);
    cout << "The Partition Label is: " << endl;
    printArray(res);
    return 0;
}