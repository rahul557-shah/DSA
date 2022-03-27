// Detect cycle in a Directed Graph(GFG) Usind DFS Traversal
#include <bits/stdc++.h>
using namespace std;
bool checkCycle(int node, vector<int> &visited, vector<int> &dfsVis, vector<int> adj[])
{
    visited[node] = 1;
    dfsVis[node] = 1;

    for (auto itr : adj[node])
    {
        if (visited[itr] == 0)
        {
            if (checkCycle(itr, visited, dfsVis, adj))
                return true;
        }
        else if (dfsVis[node])
            return true;
    }
    return false;
}
// Time->O(n+e)
// Space->O(n+e)+O(n)+O(n)+O(n)
bool isCyclic(int n, vector<int> adj[])
{
    vector<int> visited(n + 1, 0);
    vector<int> dfsVis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            if (checkCycle(i, visited, dfsVis, adj))
                return true;
        }
    }
    return false;
}
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
    }
    if (isCyclic(n, adj))
        cout << "Graph contains cycle!!" << endl;
    else
        cout << "Graph doesnot contain cycle!!" << endl;
    return 0;
}