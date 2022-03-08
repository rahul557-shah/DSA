// Non Overlapping Intervals (Leetcode Q.435)
#include <bits/stdc++.h>
using namespace std;
void printarray(vector<pair<int, int>> intervals)
{
    for (int i = 0; i < intervals.size(); i++)
        cout << "[ " << intervals[i].first << " , " << intervals[i].second << " ] ";
    cout << endl;
}
// Time->O(nlogn)
// Space->O(1)
int eraseOverlappingIntervals(vector<pair<int, int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    int count = 0;
    int left = 0, right = 1;
    while (right < n)
    {
        if (intervals[left].second <= intervals[right].first)
        {
            left = right;
            right += 1;
        }
        else if (intervals[left].second <= intervals[right].second)
        {
            count++;
            right += 1;
        }
        else if (intervals[left].second > intervals[right].second)
        {
            count++;
            left = right;
            right += 1;
        }
    }
    return count;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<pair<int, int>> intervals;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << "Enter the pair:" << endl;
        cin >> x >> y;
        intervals.push_back({x, y});
    }
    cout << "The Array is" << endl;
    printarray(intervals);
    cout << "Number of Overlapping Intervals is: " << eraseOverlappingIntervals(intervals) << endl;
    return 0;
}