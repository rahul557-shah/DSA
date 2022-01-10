// Representation of Graph (Adjacency List)
// DFS Traversal
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
void dfs(int node, vector<int> &visited, vector<int> &ans, vector<int> adj[])
{
    ans.push_back(node);
    visited[node] = 1;

    for (auto itr : adj[node])
    {
        if (visited[itr] == 0)
            dfs(itr, visited, ans, adj);
    }
}
// Time->O(n)
// Space->O(n)
vector<int> DFStraversal(int n, vector<int> adj[])
{
    vector<int> ans;
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            dfs(i, visited, ans, adj);
    }
    return ans;
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
    vector<int> ans;
    ans = DFStraversal(n, adj);
    cout << "The DFS Traversal of the Graph is: " << endl;
    printArray(ans);
    return 0;
}