// All Paths from Source to Target(Leetcode Q.797)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
void dfs(int node, vector<int> adj[], vector<vector<int>> &ans, vector<int> &path, int n)
{
    path.push_back(node);
    if (node == n - 1)
        ans.push_back(path);

    for (auto itr : adj[node])
        dfs(itr, adj, ans, path, n);
    path.pop_back();
}
// Time->O(V+E)
// Space->O(V)
vector<vector<int>> allPaths(vector<int> adj[], int n)
{
    vector<int> path;
    vector<vector<int>> ans;
    dfs(0, adj, ans, path, n);
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
    vector<vector<int>> ans = allPaths(adj, n);
    cout << "All the paths from source to target is: " << endl;
    printArray(ans);
    return 0;
}