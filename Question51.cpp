//Minimize the maximum difference between heights
#include <bits/stdc++.h>
using namespace std;
int getMinDiff(int arr[], int n, int k)
{
    vector<pair<int, int>> v;
    vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - k >= 0)
        {
            v.push_back({arr[i] - k, i});
        }
        v.push_back({arr[i] + k, i});
    }
    sort(v.begin(), v.end());
    int ele = 0;
    int left = 0;
    int right = 0;
    while (ele < n && right < v.size())
    {
        if (vis[v[right].second] == 0)
        {
            ele++;
        }
        vis[v[right].second]++;
        right++;
    }
    int ans = v[right - 1].first - v[left].first;
    while (right < v.size())
    {
        if (vis[v[left].second] == 1)
        {
            ele--;
        }
        vis[v[left].second]--;
        left++;
        while (ele < n && right < v.size())
        {
            if (vis[v[right].second] == 0)
            {
                ele++;
            }
            vis[v[right].second]++;
            right++;
        }
        if (ele == n)
            ans = min(ans, v[right - 1].first - v[left].first);
        else
            break;
    }
    return ans;
}
int main()
{
    int m;
    cout << "Enter the size of first array: " << endl;
    cin >> m;
    int A[m];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << A[i] << " ";
    }
    int k;
    printf("\nEnter the value of k: ");
    scanf("%d", &k);
    printf("Minimum difference between heights is: %d", getMinDiff(A, m, k));
    return 0;
}
