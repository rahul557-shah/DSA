// Prim's Algorithm
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
// Time->O(n^2)
// Space->O(n)
int MinCostSpanningTree(vector<pair<int, int>> adj[], int n, int key[], int mst[], int parent[])
{
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++)
    {
        int mini = INT_MAX, u;

        for (int j = 0; j < n; j++)
        {
            if (mst[j] == 0 && key[j] < mini)
            {
                mini = key[j];
                u = j;
            }
        }
        mst[u] = 1;

        for (auto itr : adj[u])
        {
            int node = itr.first;
            int weight = itr.second;
            if (mst[node] == 0 && weight < key[node])
            {
                parent[node] = u;
                key[node] = weight;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
        count += key[i];
    return count;
}
//Effective Approach
// Time->O(nlogn)
// Space->O(n)
int PrimsAlgo(vector<pair<int, int>> adj[], int n, int key[], int mst[], int parent[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mst[u] = 1;

        for (auto itr : adj[u])
        {
            int node = itr.first;
            int weight = itr.second;
            if (mst[node] == 0 && weight < key[node])
            {
                parent[node] = u;
                key[node] = weight;
                pq.push({key[node], node});
            }
        }
    }
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (key[i] != INT_MAX)
            count += key[i];
    }
    return count;
}
int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges: " << endl;
    cin >> n >> e;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v, weight;
        cout << "Enter the adjacent nodes: " << endl;
        cin >> u >> v >> weight;
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }
    int key[n], mst[n], parent[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = 0;
    }
    cout << "Minimum Cost of Spannig Tree is: " << PrimsAlgo(adj, n, key, mst, parent) << endl;
    return 0;
}