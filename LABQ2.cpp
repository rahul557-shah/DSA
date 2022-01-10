#include <bits/stdc++.h>
using namespace std;

int pass = 0, no_ele = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int size)
{

    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    pass++;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
        if (pass == 5)
        {

            cout << "5th pass array: \n";
            printArray(arr, no_ele);
        }

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elemnts:" << endl;
    cin >> n;
    int A[n];
    cout << "Enter elements in the array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    printArray(A, n);
    int ch;
    do
    {
        cout << "\nMenus are:" << endl;
        cout << "0.Exit: " << endl;
        cout << "1.Quick Sort: " << endl;
        cout << "2.For 5th pass " << endl;
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            quickSort(A,0,n-1);
            printArray(A,n);
            break;
        }
    } while (ch !=0);

    return 0;
}