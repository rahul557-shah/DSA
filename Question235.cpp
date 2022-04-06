// Find Eventual Safe State(Leetcode Q.802)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
bool dfsCycle(int node, vector<int> &visited, vector<int> &dfsVis, vector<int> adj[], vector<int> &presentCycle)
{
    visited[node] = 1;
    dfsVis[node] = 1;

    for (auto itr : adj[node])
    {
        if (visited[itr] == 0)
        {
            if (dfsCycle(itr, visited, dfsVis, adj, presentCycle))
                return presentCycle[node] = 1;
        }
        else if (visited[itr] == 1 && dfsVis[itr] == 1)
            return presentCycle[node] = 1;
    }
    dfsVis[node] = 0;
    return false;
}
// Time->O(n+e)
// Space->O(n+e)+O(n)+O(n)
vector<int> eventualSafeState(int n, vector<int> adj[])
{
    vector<int> ans;
    vector<int> visited(n, 0);
    vector<int> dfsVis(n, 0);
    vector<int> presentCycle(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            dfsCycle(i, visited, dfsVis, adj, presentCycle);
    }
    for (int i = 0; i < n; i++)
    {
        if (presentCycle[i] == 0)
            ans.push_back(i);
    }
    return ans;
}
int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges: " << endl;
    cin >> n >> e;
    vector<int> adj[n];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter the adjacent nodes: " << endl;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = eventualSafeState(n, adj);
    cout << "Safe States are: " << endl;
    printArray(ans);
    return 0;
}