// Bridge Edge in a Graph(GFG)
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], int c, int d, vector<int> &visited)
{
    visited[node] = 1;
    for (auto itr : adj[node])
    {
        if (visited[itr] == 0 && (node != c || itr != d))
            dfs(itr, adj, c, d, visited);
    }
}
// Time->O(V+E)
// Space->O(V)
int isBridge(int V, vector<int> adj[], int c, int d)
{
    vector<int> visited(V, 0);
    dfs(c, adj, c, d, visited);
    return !visited[d];
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
        adj[v].push_back(u);
    }
    int c, d;
    cout << "Enter the two nodes: " << endl;
    cin >> c >> d;
    if (isBridge(n, adj, c, d))
        cout << "Bridge is present!!" << endl;
    else
        cout << "Bridge not present!!" << endl;
    return 0;
}