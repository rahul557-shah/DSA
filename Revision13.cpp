//Merge two sorted arrays without using any extra space
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
//Time->O(nlogn)
//Space->O(1)
void MergeInplace(int A[], int m, int B[], int n)
{
    int i = 0, j = 0, k = m - 1;
    while (i <= k && j < n)
    {
        if (A[i] < B[j])
            i++;
        else
        {
            swap(A[k], B[j]);
            k--;
            j++;
        }
    }
    sort(A, A + m);
    sort(B, B + n);
}
int main()
{
    int m, n;
    cout << "Enter the size of both arrays" << endl;
    cin >> m >> n;
    int A[m], B[n];
    cout << "Enter the elements in first array: " << endl;
    for (int i = 0; i < m; i++)
        cin >> A[i];
    cout << "The first array is: " << endl;
    printArray(A, m);
    cout << "Enter the elements in second array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> B[i];
    cout << "The second array is: " << endl;
    printArray(B, n);
    MergeInplace(A, m, B, n);
    cout << "After Merging both Arrays: " << endl;
    printArray(A, m);
    printArray(B, n);
    return 0;
}