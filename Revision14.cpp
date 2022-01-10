//Merge Overlapping Intervals
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<pair<int, int>> a)
{
    for (int i = 0; i < a.size(); i++)
        cout << "[" << a[i].first << "," << a[i].second << "] ";
    cout << "\n";
}
//Time->O(nlogn)
//Space->O(n)
void MergeIntervals(vector<pair<int, int>> a)
{
    cout << "After Sorting the Array" << endl;
    sort(a.begin(), a.end());
    printArray(a);
    stack<pair<int, int>> st;
    st.push({a[0].first, a[0].second});
    for (int i = 1; i < a.size(); i++)
    {
        int start1 = st.top().first;
        int end1 = st.top().second;
        int start2 = a[i].first;
        int end2 = a[i].second;
        if (end1 >= start2)
        {
            st.pop();
            end1 = max(end1, end2);
            st.push({start1, end1});
        }
        else
        {
            st.push({start2, end2});
        }
    }
    cout << "After Merging the Intervals " << endl;
    while (!st.empty())
    {
        cout << "[" << st.top().first << "," << st.top().second << "]";
        st.pop();
    }
}
//Time->O(nlogn)
//Space->O(1)
vector<vector<int>> MergeOverLappingIntervals(vector<pair<int, int>> &a)
{
    if (a.size() == 0)
        return vector<vector<int>>{0};
    vector<vector<int>> res;
    sort(a.begin(), a.end());
    int first = a[0].first;
    int last = a[0].second;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i].first <= last && a[i].second >= first)
        {
            last = max(last, a[i].second);
        }
        else
        {
            vector<int> temp = {first, last};
            res.push_back(temp);
            first = a[i].first;
            last = a[i].second;
        }
    }
    vector<int> temp = {first, last};
    res.push_back(temp);
    return res;
}
int main()
{
    int x, y, n;
    vector<pair<int, int>> a;
    vector<vector<int>> res;
    cout << "Enter the size" << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a.push_back({x, y});
    }
    cout << "The Array is: " << endl;
    printArray(a);
    cout << "After Merging the Intervals " << endl;
    res = MergeOverLappingIntervals(a);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[" << res[i][0] << "," << res[i][1] << "] ";
    }
    return 0;
}