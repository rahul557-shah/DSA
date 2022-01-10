//Intersection And Union of two unsorted arrays
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
void Intersection(int A[], int m, int B[], int n)
{
    int i = 0, j = 0, k = 0;
    int C[min(m, n)];
    sort(A, A + m);
    sort(B, B + n);
    while (i < m && j < n)
    {
        if (A[i] == B[j])
        {
            C[k++] = A[i++];
            j++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else
            j++;
    }
    for (int i = 0; i < k; i++)
        cout << C[i] << " ";
    cout << endl;
}
void Union(int A[], int m, int B[], int n)
{
    int i = 0, j = 0, k = 0;
    int C[m + n];
    sort(A, A + m);
    sort(B, B + n);
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else if (A[i] > B[j])
        {
            C[k++] = B[j++];
        }
        else
        {
            C[k++] = A[i++];
            j++;
        }
    }
    while (i < m)
    {
        C[k++] = A[i++];
    }
    while (j < n)
    {
        C[k++] = B[j++];
    }
    for (int i = 0; i < k; i++)
        cout << C[i] << " ";
    cout << endl;
}
int main()
{
    int m, n;
    cout << "Enter the size of two arrays" << endl;
    cin >> m >> n;
    int A[m], B[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < m; i++)
        cin >> A[i];
    cout << "The first array is: " << endl;
    printArray(A, m);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> B[i];
    cout << "The second array is: " << endl;
    printArray(B, n);
    cout << "The Intersection of two arrays is: " << endl;
    Intersection(A, m, B, n);
    cout << "The Union of two arrays is: " << endl;
    Union(A, m, B, n);
    return 0;
}