// Bipartite Graph(Leetcode Q.785)
#include <bits/stdc++.h>
using namespace std;

bool isBipartiteGraph(int src, vector<int> &color, vector<int> adj[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto itr : adj[node])
        {
            if (color[itr] == -1)
            {
                color[itr] = 1 - color[node];
                q.push(itr);
            }
            else if (color[itr] == color[node])
                return false;
        }
    }
    return true;
}
// Time->O(n+e)
// Space->O(n+e)+O(n)+O(n)
bool checkBipartite(vector<int> adj[], int n)
{
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartiteGraph(i, color, adj))
                return false;
        }
    }
    return true;
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
    if (checkBipartite(adj, n))
        cout << "Yes the graph is Bipartite!!" << endl;
    else
        cout << "Not Bipartite!!" << endl;
    return 0;
}