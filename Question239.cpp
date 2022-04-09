// Jump Game III (Leetcode Q.1306)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
// Time->O(n)
// Space->O(n)
bool canReach(vector<int> &arr, int start)
{
    int n = arr.size();
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int node = q.front();
            q.pop();

            if (node - arr[node] >= 0)
            {
                if (arr[node - arr[node]] == 0)
                    return true;
                else if (arr[node - arr[node]] > 0)
                    q.push(node - arr[node]);
            }

            if (node + arr[node] < n)
            {
                if (arr[node + arr[node]] == 0)
                    return true;
                else if (arr[node + arr[node]] > 0)
                    q.push(node + arr[node]);
            }
            arr[node] = -1;
        }
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<int> arr;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "The Array is: " << endl;
    printArray(arr);
    int start;
    cout << "Enter the start index: " << endl;
    cin >> start;
    if (canReach(arr, start))
        cout << "We can reach to O!!" << endl;
    else
        cout << "Cannot Reach!!" << endl;
    return 0;
}