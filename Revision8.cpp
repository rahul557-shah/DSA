//Cyclically Rotate an array
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
void RotateByOne(int A[], int n)
{
    int temp = A[0];
    for (int i = 0; i < n - 1; i++)
    {
        A[i] = A[i + 1];
    }
    A[n - 1] = temp;
}
//Time->O(n^2)
void RotateByK(int A[], int n, int k)
{
    for (int i = 0; i < k; i++)
        RotateByOne(A, n);
}
//Reversal Algorithm for rotating an array
void Reverse(int A[], int start, int end)
{
    while (start < end)
    {
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;
        start++;
        end--;
    }
}
//Time->O(n)
void RotateByRev(int A[], int d, int n)
{
    if (d == 0)
        return;
    d = d % n;
    Reverse(A, 0, d - 1);
    Reverse(A, d, n - 1);
    Reverse(A, 0, n - 1);
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
    cout << "After Rotating :" << endl;
    RotateByRev(A, k, n);
    printArray(A, n);
    return 0;
}