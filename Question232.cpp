// Keys and Rooms (Leetcode Q.841)
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> rooms[], vector<int> &visited)
{
    for (auto itr : rooms[node])
    {
        if (visited[itr] == 0)
        {
            visited[itr] = 1;
            dfs(itr, rooms, visited);
        }
    }
}
// Time->O(V+E)
// Spcae->O(V)
bool canVisit(vector<int> rooms[],int n)
{
    vector<int> visited(n, 0);
    visited[0] = 1;
    dfs(0, rooms, visited);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
            return false;
    }
    return true;
}
int main()
{
    int n, e;
    cout << "Enter the number of vertices and edges: " << endl;
    cin >> n >> e;
    vector<int> rooms[n];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter the adjacent nodes: " << endl;
        cin >> u >> v;
        rooms[u].push_back(v);
    }
    if (canVisit(rooms,n))
        cout << "All the rooms are visited!!" << endl;
    else
        cout << "Not visited!!" << endl;
    return 0;
}