//Merge Overlapping Intervals
#include <bits/stdc++.h>
using namespace std;
//Time->O(nlogn)
//Space->O(n)
int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<pair<int, int>> a;
    int x, y;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    stack<pair<int, int>> s;
    s.push({a[0].first, a[0].second});
    for (int i = 1; i < n; i++)
    {
        int start1 = s.top().first;
        int end1 = s.top().second;
        int start2 = a[i].first;
        int end2 = a[i].second;
        if (end1 >= start2)
        {
            s.pop();
            end1 = max(end1, end2);
            s.push({start1, end1});
        }
        else
            s.push({start2, end2});
    }

    cout << "After Merging the intervals: " << endl;
    while (!s.empty())
    {
        cout << "[" << s.top().first << "," << s.top().second << "]";
        s.pop();
    }
    return 0;
}