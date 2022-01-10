//Remove Duplicates from a sorted array and return the new length
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}
//Time->O(n)
//Space->O(1)
int RemoveDup(int A[], int n)
{
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] != A[i + 1])
        {
            A[j] = A[i];
            j++;
        }
    }
    A[j] = A[n - 1];
    return j + 1;
}
//Time->O(n)
//Space->O(1)
int RemoveDuplicates(int A[], int n)
{
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] != A[j])
        {
            j++;
            A[j] = A[i];
        }
    }
    return j + 1;
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The Array is: " << endl;
    printArray(A, n);
    cout << "After Removing Duplicates The New Size is: " << RemoveDuplicates(A, n) << endl;
    return 0;
}