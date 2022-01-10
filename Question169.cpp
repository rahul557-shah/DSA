// Minimum number of platforms
#include <bits/stdc++.h>
using namespace std;
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
// Time->O(nlogn)
// Space->O(1)
int minimumPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 1, j = 0;
    int platform_needed = 1, result = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            platform_needed++;
            i++;
        }
        else if (arr[i] > dep[j])
        {
            platform_needed--;
            j++;
        }
        result = max(result, platform_needed);
    }
    return result;
}
int main()
{
    int n;
    cout << "Enter the number of trains: " << endl;
    cin >> n;
    int arr[n], dep[n];
    cout << "Enter the arrival time: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the departure time: " << endl;
    for (int i = 0; i < n; i++)
        cin >> dep[i];
    cout << "The Arrival Array is: " << endl;
    printArray(arr, n);
    cout << "The Departure Array is: " << endl;
    printArray(dep, n);
    cout << "Minimum number of platforms needed is: " << minimumPlatform(arr, dep, n) << endl;
    return 0;
}