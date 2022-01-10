// Representation of Graph (Adjacency List)
// BFS Traversal
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
// Time->O(n)
// Space->O(n)
vector<int> BFStraversal(vector<int> adj[], int n)
{
    vector<int> bfs;
    queue<int> q;
    vector<int> visited(n + 1, 0);
    q.push(1);
    visited[1] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto itr : adj[node])
        {
            if (visited[itr] == 0)
            {
                q.push(itr);
                visited[itr] = 1;
            }
        }
    }
    return bfs;
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
    ans = BFStraversal(adj, n);
    cout << "The BFS Traversal of the Graph is: " << endl;
    printArray(ans);
    return 0;
}