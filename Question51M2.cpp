// Minimize the maximum difference between heights
#include <bits/stdc++.h>
using namespace std;
// Time->O(nlogn)
// Space->O(1)
int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;
    int min_ele, max_ele;
    for (int i = 0; i < n - 1; i++)
    {
        min_ele = min(smallest, arr[i + 1] - k);
        max_ele = max(largest, arr[i] + k);
        if (min_ele < 0)
            continue;
        ans = min(ans, max_ele - min_ele);
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
