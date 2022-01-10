//Reverse an Array
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
void Reverse(int A[], int n)
{
    int l = 0, h = n - 1;
    while (l < h)
    {
        swap(A[l], A[h]);
        l++;
        h--;
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
    Reverse(A, n);
    cout << "After Reversing" << endl;
    printArray(A, n);
    return 0;
}