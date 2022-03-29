// Course Schedule(Leetcode Q.207)
#include <bits/stdc++.h>
using namespace std;
// Time->O(n+e)
// Space->O(n+e)+O(n)+O(n)
bool courseSchedule(int n, vector<pair<int, int>> &prerequisite)
{
    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);
    queue<int> q;
    for (auto itr : prerequisite)
    {
        adj[itr.second].push_back(itr.first);
        indegree[itr.first]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (auto itr : adj[node])
        {
            indegree[itr]--;
            if (indegree[itr] == 0)
                q.push(itr);
        }
    }
    if (count == n)
        return true;
    else
        return false;
}
int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges: " << endl;
    cin >> n >> e;
    vector<pair<int, int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter the adjacent nodes: " << endl;
        cin >> u >> v;
        adj.push_back(make_pair(u, v));
    }
    if (courseSchedule(n, adj))
        cout << "Tasks can be finished!!" << endl;
    else
        cout << "Tasks can't be finished" << endl;
    return 0;
}