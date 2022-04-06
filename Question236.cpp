// Possible paths between two vertices(GFG)
#include <bits/stdc++.h>
using namespace std;
int dfsCount(vector<int> adj[], int src, int dest, int par)
{
    if (src == dest)
        return 1;
    int ans = 0;
    for (auto itr : adj[src])
    {
        if (itr != par)
            ans += dfsCount(adj, itr, dest, src);
    }
    return ans;
}
// Time->O(V+E)
// Space->O(1)
int allPossiblePaths(vector<int> adj[], int source, int destination)
{
    return dfsCount(adj, source, destination, -1);
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
    int src, dest;
    cout << "Enter the source and destination vertices: " << endl;
    cin >> src >> dest;
    cout << "Number of Paths is: " << allPossiblePaths(adj, src, dest) << endl;
    return 0;
}