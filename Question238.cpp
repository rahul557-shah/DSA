// Reorder Routes to Make All Paths Lead to the City Zero (Leetcode Q.1466)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < edges[0].size(); j++)
            cout << edges[i][j] << " ";
        cout << endl;
    }
}
void dfs(int node, vector<vector<int>> graph, vector<int> &visited, int &ans)
{
    visited[node] = 1;

    for (auto itr : graph[node])
    {
        if (visited[abs(itr)] == 0)
        {
            if (itr < 0)
                ans++;
            dfs(abs(itr), graph, visited, ans);
        }
    }
}
// Time->O(V+E)
// Space->O(V+E)+O(V)
int minimumReorder(vector<vector<int>> edges, int v)
{
    int ans = 0;
    vector<int> visited(v, 0);
    vector<vector<int>> graph(v);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u].push_back(-v);
        graph[v].push_back(u);
    }
    dfs(0, graph, visited, ans);
    return ans;
}
// Time->O(V+E)
// Space->O(V)+O(V)+O(V)
int minReorderBFS(vector<vector<int>> edges, int v)
{
    queue<int> q;
    vector<vector<int>> adj(v);
    vector<vector<int>> back(v);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        back[v].push_back(u);
    }
    vector<int> visited(v, 0);
    q.push(0);
    visited[0] = 1;
    int res = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto itr : adj[node])
        {
            if (visited[itr] == 0)
            {
                q.push(itr);
                res++;
                visited[itr] = 1;
            }
        }
        for (auto itr : back[node])
        {
            if (visited[itr] == 0)
            {
                q.push(itr);
                visited[itr] = 1;
            }
        }
    }
    return res;
}
int main()
{
    int v, n;
    cout << "Enter the number of vertex: " << endl;
    cin >> v;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the edges: " << endl;
        for (int j = 0; j < 2; j++)
            cin >> edges[i][j];
    }
    cout << "The Graph is: " << endl;
    printArray(edges);
    cout << "Minimum number of changes in the graph is: " << minReorderBFS(edges, v) << endl;
    return 0;
}