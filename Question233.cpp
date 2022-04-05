// Number of Provinces(Leetcode Q.547)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> isConnected)
{
    for (int i = 0; i < isConnected.size(); i++)
    {
        for (int j = 0; j < isConnected[0].size(); j++)
            cout << isConnected[i][j] << " ";
        cout << endl;
    }
}
void dfs(int node, vector<vector<int>> &isConnected, vector<int> &visited, int n)
{
    visited[node] = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && isConnected[node][i] == 1)
            dfs(i, isConnected, visited, n);
    }
}
// Time->O(V+E)
// Spcae->O(V)
int numberOfProvinces(vector<vector<int>> isConnected)
{
    int n = isConnected.size();
    vector<int> visited(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            dfs(i, isConnected, visited, n);
        }
    }
    return count;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the elements: " << endl;
        for (int j = 0; j < n; j++)
            cin >> isConnected[i][j];
    }
    cout << "The isConnected are: " << endl;
    printArray(isConnected);
    cout << "The number of provinces is: " << numberOfProvinces(isConnected) << endl;
    return 0;
}