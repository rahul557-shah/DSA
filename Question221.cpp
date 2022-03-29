// Dijkstra Algorithm
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
vector<int> dijkstraAlgo(vector<pair<int, int>> adj[], int n, int src)
{
    vector<int> distance(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto itr : adj[node])
        {
            int next = itr.first;
            int nextDist = itr.second;
            if (dist + nextDist < distance[next])
            {
                distance[next] = distance[node] + nextDist;
                pq.push(make_pair(distance[next], next));
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
    vector<pair<int, int>> adj[n + 1];
    int u, v, wt;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter the adjacent nodes: " << endl;
        cin >> u >> v;
        cout << "Enter the weight: " << endl;
        cin >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }
    int src;
    cout << "Enter the source vertex: " << endl;
    cin >> src;
    vector<int> ans = dijkstraAlgo(adj, n, src);
    cout << "Minimum Distance is: " << endl;
    printArray(ans);
    return 0;
}