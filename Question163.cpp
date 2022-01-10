// N meetings in one room(Activity Selection Problem)
#include <bits/stdc++.h>
using namespace std;
struct Meeting
{
    int start;
    int end;
    int pos;
};
bool Comparator(Meeting m1, Meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    else
        return false;
}
// Time->O(nlogn)
// Space->O(1)
vector<int> nMeetings(int start[], int end[], int n)
{
    struct Meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i + 1;
    }
    sort(meet, meet + n, Comparator);
    vector<int> ans;
    int limit = meet[0].end;
    ans.push_back(meet[0].pos);

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        {
            ans.push_back(meet[i].pos);
            limit = meet[i].end;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number of meetings: " << endl;
    cin >> n;
    int start[n], end[n];
    cout << "Enter the start time: " << endl;
    for (int i = 0; i < n; i++)
        cin >> start[i];
    cout << "Enter the end time: " << endl;
    for (int i = 0; i < n; i++)
        cin >> end[i];
    cout << "The start and end time of meeting are: " << endl;
    for (int i = 0; i < n; i++)
        cout << " [" << start[i] << " " << end[i] << "]";
    vector<int> ans;
    ans = nMeetings(start, end, n);
    cout << "\nThe Meetings that can be accomodated are: " << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}