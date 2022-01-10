// Implementation of Heap Sort usind MaxHeap
#include <bits/stdc++.h>
using namespace std;
void max_heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}
void bulidMaxHeap(int arr[], int n)
{
    //Creating MaxHeap
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);
}
void heapSort(int arr[], int n)
{
    bulidMaxHeap(arr, n);
    //Deleting Elements from MaxHeap
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
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
    cout << "ENter the size of the array: " << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The Array is: " << endl;
    printArray(A, n);
    cout << "Sorted Array in Ascending Order is " << endl;
    heapSort(A, n);
    printArray(A, n);
    return 0;
}
