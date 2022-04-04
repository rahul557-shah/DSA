// Number of operations to make network connected(Leetcode Q,1319)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> connections)
{
    for (int i = 0; i < connections.size(); i++)
    {
        for (int j = 0; j < connections[0].size(); j++)
            cout << connections[i][j] << " ";
        cout << endl;
    }
}
void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &visited)
{
    visited[node] = 1;
    for (auto itr : adj[node])
    {
        if (visited[itr] == 0)
            dfs(itr, adj, visited);
    }
}
// Time->O(V+E)
// Spcae->O(V+E)+O(n)
int makeConnections(vector<vector<int>> &connections, int n)
{
    unordered_map<int, vector<int>> adj;
    vector<int> visited(n, 0);
    int edges = 0;
    // Creating adjacency list
    for (int i = 0; i < connections.size(); i++)
    {
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
        edges += 1;
    }
    int components = 0;
    // Counting the components
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            components += 1;
            dfs(i, adj, visited);
        }
    }
    if (edges < n - 1)
        return -1;
    // Finding Redundant Edges
    int redundant = edges - ((n - 1) - (components - 1));
    if (redundant >= components - 1)
        return components - 1;
    return -1;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<vector<int>> connections(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the elements: " << endl;
        for (int j = 0; j < 2; j++)
            cin >> connections[i][j];
    }
    cout << "The Connections is: " << endl;
    printArray(connections);
    int nodes;
    cout << "Enter the number of nodes: " << endl;
    cin >> nodes;
    cout << "Number of operations to make network connected: " << makeConnections(connections,nodes) << endl;
    return 0;
}