#include <bits/stdc++.h>
using namespace std;
void mergeAll(vector<int> &A, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    vector<int> B(high + 1);
    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i <= mid)
        B[k++] = A[i++];
    while (j <= high)
        B[k++] = A[j++];
    for (int i = low; i <= high; i++)
        A[i] = B[i];
}
void mergeSort(vector<int> &A, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);

        mergeAll(A, low, mid, high);
    }
}
int partitionFun(vector<int> &A, int low, int high)
{
    int i = low - 1, pivot = A[high];
    for (int j = low; j <= high - 1; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[high]);
    return i + 1;
}
void quickSort(vector<int> &A, int low, int high)
{
    if (low < high)
    {
        int partition = partitionFun(A, low, high);
        quickSort(A, low, partition - 1);
        quickSort(A, partition + 1, high);
    }
}
int main()
{
    vector<int> A = {3, 1, 5, 2, 7, 4, 6, 9, 8, 10};
    int n = A.size();
    quickSort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}