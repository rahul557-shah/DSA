// Find the Winner of the Circular Game(Leetcode Q.1823)
#include <bits/stdc++.h>
using namespace std;
// Time->O(n)
// Space->O(n)
int findTheWinner(int n, int k)
{
    if (k == 1)
        return n;
    queue<int> q;
    int count = 1;
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (!q.empty() && q.size() > 1)
    {
        if (count == k)
        {
            q.pop();
            count = 1;
        }
        else
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
            count++;
        }
    }
    return q.front();
}
int main()
{
    int n, k;
    cout << "Enter the values of n and k: " << endl;
    cin >> n >> k;
    cout << "The Winner of Circular Game is: " << findTheWinner(n, k) << endl;
    return 0;
}