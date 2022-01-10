// Quick Sort an array
#include <bits/stdc++.h>
using namespace std;
int Partition(int A[], int l, int h)
{
    int i = l;
    int j = h;
    int pivot = A[l];
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(A[i], A[j]);
    } while (i < j);
    swap(A[l], A[j]);
    return j;
}
void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
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
    cout << "\nQuick Sorting" << endl;
    QuickSort(A, 0, n);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}