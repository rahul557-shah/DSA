// Find a Town Judge(Leetcode Q.997)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<vector<int>> trust)
{
    for (int i = 0; i < trust.size(); i++)
    {
        cout << trust[i][0] << " , " << trust[i][1] << endl;
    }
}
// Time->O(n)
// Space->O(n)
int townJudge(vector<vector<int>> &trust, int N)
{
    vector<pair<int, int>> arr(N + 1, {0, 0});
    for (int i = 0; i < trust.size(); i++)
    {
        arr[trust[i][0]].first += 1;
        arr[trust[i][1]].second += 1;
    }
    for (int i = 1; i <= N; i++)
    {
        if (arr[i].first == 0 && arr[i].second == N - 1)
            return i;
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<vector<int>> trust(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the pair: " << endl;
        for (int j = 0; j < trust[0].size(); j++)
            cin >> trust[i][j];
    }
    cout << "The Pair is: " << endl;
    printArray(trust);
    int N;
    cout << "Enter the value of N: " << endl;
    cin >> N;
    cout << "The Town Judge is: " << townJudge(trust, N) << endl;
    return 0;
}