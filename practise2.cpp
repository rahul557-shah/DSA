//Merge Sort an array
#include <bits/stdc++.h>
using namespace std;
void Merge(int A[], int l, int mid, int h)
{
    int i = l, k = l;
    int j = mid + 1;
    int B[h + 1];
    while (i <= mid && j <= h)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= h)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = l; i <= h; i++)
        A[i] = B[i];
}
void MergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The Array is: " << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\nMerge Sorting" << endl;
    MergeSort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}