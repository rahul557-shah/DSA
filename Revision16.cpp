//Count Inversions
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
//Time->O(n^2)
//Space->O(1)
int CountInversions(int A[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
                count++;
        }
    }
    return count;
}
//Time->O(nlogn)
//Space->O(n)
int Merge(int A[], int l, int mid, int h, int n)
{
    int count = 0;
    int i = l, k = l;
    int j = mid + 1;
    int temp[n];
    while (i <= mid && j <= h)
    {
        if (A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
            count += mid - i + 1;
        }
    }
    while (i <= mid)
        temp[k++] = A[i++];
    while (j <= h)
        temp[k++] = A[j++];
    for (int i = l; i < k; i++)
        A[i] = temp[i];
    return count;
}
int MergeSort(int A[], int l, int h, int n)
{
    int count = 0;
    if (l < h)
    {
        int mid = (l + h) / 2;
        count += MergeSort(A, l, mid, n);
        count += MergeSort(A, mid + 1, h, n);

        count += Merge(A, l, mid, h, n);
    }
    return count;
}
int main()
{
    int m;
    cout << "Enter the size " << endl;
    cin >> m;
    int A[m];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < m; i++)
        cin >> A[i];
    cout << "The array is: " << endl;
    printArray(A, m);
    cout << "The Total number of Inversions is: " << MergeSort(A, 0, m - 1, m) << endl;
    return 0;
}