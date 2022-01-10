// Job Sequencing Problem
#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;
    int profit;
    int deadline;
};
bool Comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}
// Time->O(nlogn+m*n)
// Space->O(m)
vector<int> JobSequencing(Job arr[], int n)
{
    vector<int> res;
    sort(arr, arr + n, Comparison);
    int maxi = arr[0].deadline;
    for (int i = 1; i < n; i++)
        maxi = max(maxi, arr[i].deadline);
    int slot[maxi + 1];
    for (int i = 0; i <= maxi; i++)
        slot[i] = -1;
    int countJobs = 0, jobProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
            }
        }
    }
    res.push_back(countJobs);
    res.push_back(jobProfit);
    return res;
}
int main()
{
    int n;
    cout << "Enter the number of jobs: " << endl;
    cin >> n;
    struct Job arr[n];
    cout << "Enter the details: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].profit >> arr[i].deadline;
    }
    cout << "The Jobs Are: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i].id << " " << arr[i].profit << " " << arr[i].deadline << endl;
    vector<int> res;
    res = JobSequencing(arr, n);
    cout << "The Number of Jobs sequenced with profit is: " << endl;
    cout << res[0] << " " << res[1] << endl;
    return 0;
}