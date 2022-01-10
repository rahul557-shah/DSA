// Merge overlapping Intervals in O(n Log n) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;
struct Array
{
    int start;
    int end;
};
bool Comparison(Array a, Array b)
{
    return a.start < b.start;
}
void Merge(Array arr[], int n)
{
    int index = 0;
    sort(arr, arr + n, Comparison);
    for (int i = 1; i < n; i++)
    {
        if (arr[index].end >= arr[i].start)
        {
            arr[index].end = max(arr[index].end, arr[i].end);
            //arr[index].start = max(arr[index].start, arr[i].start);
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }
    cout << "\nThe Merged Intervals are: ";
    for (int i = 0; i <= index; i++)
        cout << "[" << arr[i].start << ", " << arr[i].end << "] ";
}
int main()
{
    Array arr[] = { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    Merge(arr, n);
    return 0;
}
