// Keys and Rooms (Leetcode Q.841)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> rooms)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        for (int j = 0; j < rooms[0].size(); j++)
            cout << rooms[i][j] << " ";
        cout << endl;
    }
}
void dfs(int node, vector<vector<int>> &rooms, vector<int> &visited)
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
bool canVisit(vector<vector<int>> &rooms)
{
    int n = rooms.size();
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
    int n, m;
    cout << "Enter the size: " << endl;
    cin >> n >> m;
    vector<vector<int>> rooms(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the elements: " << endl;
        for (int j = 0; j < m; j++)
            cin >> rooms[i][j];
    }
    cout << "The Rooms are: " << endl;
    printArray(rooms);
    if (canVisit(rooms))
        cout << "All the rooms are visited!!" << endl;
    else
        cout << "Not visited!!" << endl;
    return 0;
}