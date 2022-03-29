// Course Schedule II(Leetcode Q.210)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
// Time->O(n+e)
// Space->O(n+e)+O(n)+O(n)
vector<int> courseSchedule(int n, vector<pair<int, int>> &prerequisite)
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
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto itr : adj[node])
        {
            indegree[itr]--;
            if (indegree[itr] == 0)
                q.push(itr);
        }
    }
    if (topo.size() == n)
        return topo;
    else
        return {};
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
    vector<int> ans = courseSchedule(n, adj);
    cout << "Correct Course Ordering is: " << endl;
    printArray(ans);
    return 0;
}