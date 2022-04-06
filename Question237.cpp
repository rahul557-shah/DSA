// Find if Path Exists In Graph(Leetcode Q.1971)
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
bool dfsPath(vector<vector<int>> &graph, int src, int dest, vector<int> &visited)
{
    if (src == dest)
        return true;
    visited[src] = 1;

    for (auto itr : graph[src])
    {
        if (visited[itr] == 0)
        {
            if (dfsPath(graph, itr, dest, visited))
                return true;
        }
    }
    return false;
}
// Time->O(V+E)
// Space->O(V)
bool pathExists(vector<vector<int>> edges, int source, int destination, int n)
{
    vector<int> visited(n, 0);
    vector<vector<int>> graph(n);
    if (source == destination)
        return true;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return dfsPath(graph, source, destination, visited);
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
    int src, dest;
    cout << "Enter the source and destination vertices: " << endl;
    cin >> src >> dest;
    if (pathExists(edges, src, dest, v))
        cout << "Path Exists!!" << endl;
    else
        cout << "Path doesnot exist!!" << endl;
    return 0;
}