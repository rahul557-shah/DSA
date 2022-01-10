//Sort 0s,1s,2s in an array
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
void Sort012(int A[], int n)
{
    int l, mid, h;
    l = mid = 0;
    h = n - 1;
    while (mid < h)
    {
        switch (A[mid])
        {
        case 0:
            swap(A[mid], A[l]);
            l++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(A[mid], A[h]);
            h--;
            break;
        }
    }
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
    cout << "After Sorting: " << endl;
    Sort012(A, n);
    printArray(A, n);
    return 0;
}