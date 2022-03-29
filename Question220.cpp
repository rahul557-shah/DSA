// Shortest Path in an Undirected Graph with unit weights
#include <bits/stdc++.h>
using namespace std;
// Time->O(n+e)
// Space->O(n+e)+O(n)+O(n)
void printArray(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
vector<int> shortestPath(int n, int src, vector<int> adj[])
{
    vector<int> distance(n, INT_MAX);
    queue<int> q;
    distance[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto itr : adj[node])
        {
            if (distance[node] + 1 < distance[itr])
            {
                distance[itr] = distance[node] + 1;
                q.push(itr);
            }
        }
    }
    return distance;
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
    int src;
    cout << "Enter the source: " << endl;
    cin >> src;
    vector<int> ans = shortestPath(n, src, adj);
    cout << "The Distance Array is: " << endl;
    printArray(ans);
    return 0;
}