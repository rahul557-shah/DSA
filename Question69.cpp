//Median of two Sorted Arrays of both equal sizes
#include <bits/stdc++.h>
using namespace std;
//Time->O(n)
double MedianOfSorted(int A[], int B[], int n)
{
    int count;
    int i, j;
    i = j = 0;
    int m1, m2;
    m1 = m2 = -1;
    for (count = 0; count <= n; count++)
    {
        if (i == n)
        {
            m1 = m2;
            m2 = B[0];
            break;
        }
        else if (j == n)
        {
            m1 = m2;
            m2 = A[0];
            break;
        }
        if (A[i] <= B[j])
        {
            m1 = m2;
            m2 = A[i];
            i++;
        }
        else
        {
            m1 = m2;
            m2 = B[j];
            j++;
        }
    }
    return (m1 + m2) / 2.0;
}
int main()
{
    int m;
    cout << "Enter the size of both arrays: " << endl;
    cin >> m;
    int A[m];
    int B[m];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\nEnter the elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << B[i] << " ";
    }
    cout << "\nMedian of two sorted Arrays is: " << MedianOfSorted(A, B, m) << endl;
    return 0;
}