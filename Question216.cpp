// Topological Sort of a Graph
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
void topoSortDFS(int node, vector<int> &visited, stack<int> &stk, vector<int> adj[])
{
    visited[node] = 1;

    for (auto itr : adj[node])
    {
        if (visited[itr] == 0)
            topoSortDFS(itr, visited, stk, adj);
    }
    stk.push(node);
}
// Time->O(n+e)
// Space->O(n+e)+O(n)+O(n)
vector<int> topologicalSort(int n, vector<int> adj[])
{
    vector<int> visited(n + 1, 0);
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            topoSortDFS(i, visited, stk, adj);
    }
    vector<int> topo;
    while (!stk.empty())
    {
        topo.push_back(stk.top());
        stk.pop();
    }
    return topo;
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
    vector<int> ans = topologicalSort(n, adj);
    cout << "Topological Sort: " << endl;
    printArray(ans);
    return 0;
}