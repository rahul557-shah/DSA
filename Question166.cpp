// Detect a cycle in an Undirected Graph using BFS Traversal
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
bool detectCycle(int s, vector<int> &visited, vector<int> adj[])
{
    queue<pair<int, int>> q;
    q.push({s, -1});
    visited[s] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto itr : adj[node])
        {
            if (visited[itr] == 0)
            {
                q.push({itr, node});
                visited[itr] = 1;
            }
            else if (parent != itr)
                return true;
        }
    }
    return false;
}
// Time->O(n)
// Space->O(n)
bool isCycle(int n, vector<int> adj[])
{
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            if (detectCycle(i, visited, adj))
                return true;
        }
    }
    return false;
}
// Space->O(n+2e)
int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges: " << endl;
    cin >> n >> e;
    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter the adjacent nodes: " << endl;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (isCycle(n, adj))
        cout << "The Undirected Graph has cycle!!!" << endl;
    else
        cout << "No Cycle!!!" << endl;
    return 0;
}