// Topological Sort of a Graph(Using BFS[Kahn's Algorithm])
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
// Time->O(n+e)
// Space->O(n+e)+O(n)+O(n)
vector<int> topologicalSort(int n, vector<int> adj[])
{

    vector<int> indegree(n + 1, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        for (auto itr : adj[i])
            indegree[itr]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto itr : adj[node])
        {
            indegree[itr]--;
            if (indegree[itr] == 0)
                q.push(itr);
        }
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