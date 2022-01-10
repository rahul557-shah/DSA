// Implementation of Heap Sort usind MinHeap
#include <bits/stdc++.h>
using namespace std;
void min_heapify(int arr[], int n, int i)
{
    int smallest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (i != smallest)
    {
        swap(arr[i], arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}
void buildMinHeap(int arr[], int n)
{
    //Creating MaxHeap
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(arr, n, i);
}
void heapSort(int arr[], int n)
{
    buildMinHeap(arr, n);
    //Deleting Elements from MaxHeap
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        min_heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The Array is: " << endl;
    printArray(A, n);
    cout << "Sorted Array in Descending order is " << endl;
    heapSort(A, n);
    printArray(A, n);
    return 0;
}
