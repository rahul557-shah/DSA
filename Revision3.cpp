//Kth Largest Element
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
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
    swap(A[j], A[l]);
    return j;
}
void QuickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int j = Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}
int KthLargest(int A[], int n, int k)
{
    QuickSort(A, 0, n);
    return A[n - k];
}
int main()
{
    int n;
    cout << "Enter the size" << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The array is: " << endl;
    printArray(A, n);
    int k;
    cout << "Enter the value of k" << endl;
    cin >> k;
    cout << "Kth Largest Element is: " << KthLargest(A, n, k) << endl;
    return 0;
}