//Count Pair with given sum
#include <bits/stdc++.h>
using namespace std;
//Time->O(n)
//Space->O(n)
int getPairsCount(int arr[], int n, int sum)
{
    unordered_map<int, int> m;
    int count = 0, x;
    for (int i = 0; i < n; i++)
    {
        x = sum - arr[i];
        if (m[x] == 0)
            m[arr[i]]++;
        else
        {
            count += m[x];
            m[arr[i]]++;
        }
    }
    return count;
}

int main()
{
    int arr[10];
    int n, sum;
    cout << "Enter the size: " << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nEnter the sum: " << endl;
    cin >> sum;
    cout << "Count of pairs is: " << getPairsCount(arr, n, sum);
    return 0;
}
