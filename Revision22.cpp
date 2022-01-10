//Merge Sorted Arrays(LeetCode Q88)
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int m)
{
    for (int i = 0; i < m; i++)
        cout << A[i] << " ";
    cout << "\n";
}
//Time->O(m+n)
//Space->O(1)
void MergeSorted(int A[], int m, int B[], int n)
{
    int p1 = m - 1, p2 = n - 1;
    int i = m + n - 1;
    while (p2 >= 0)
    {
        if (p1 >= 0 && A[p1] <= B[p2])
            A[i--] = B[p2--];
        else
            A[i--] = A[p1--];
    }
}
int main()
{
    int m, n;
    cout << "Enter the size of both arrays" << endl;
    cin >> m >> n;
    int A[m + n], B[n];
    cout << "Enter the elements in first array: " << endl;
    for (int i = 0; i < m; i++)
        cin >> A[i];
    for (int i = m; i < m + n; i++)
        A[i] = 0;
    cout << "The first array is: " << endl;
    printArray(A, m + n);
    cout << "Enter the elements in second array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> B[i];
    cout << "The second array is: " << endl;
    printArray(B, n);
    cout << "After Merging in the first array :" << endl;
    MergeSorted(A, m, B, n);
    printArray(A, m + n);
    return 0;
}