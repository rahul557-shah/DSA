//Maximum and Minimum element in an Array
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
void MaxMin(int A[], int n)
{
    int max, min;
    if (n == 1)
    {
        max = A[0];
        min = A[0];
    }
    else
    {
        if (A[0] > A[1])
        {
            max = A[0];
            min = A[1];
        }
        else
        {
            max = A[1];
            min = A[0];
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }
    cout << "Maximum Element is: " << max << endl;
    cout << "Minimum Element is: " << min << endl;
}
void MaxMin2(int A[], int n)
{
    int i, max, min;
    if (n % 2 == 0)
    {
        if (A[0] > A[1])
        {
            max = A[0];
            min = A[1];
        }
        else
        {
            max = A[1];
            min = A[0];
        }
        i = 2;
    }
    else
    {
        max = A[0];
        min = A[0];
        i = 1;
    }
    while (i < n - 1)
    {
        if (A[i] > A[i + 1])
        {
            if (A[i] > max)
                max = A[i];
            if (A[i + 1] < min)
                min = A[i + 1];
        }
        else
        {
            if (A[i + 1] > max)
                max = A[i + 1];
            if (A[i] < min)
                min = A[i];
        }
        i += 2;
    }
    cout << "Maximum Element is: " << max << endl;
    cout << "Minimum Element is: " << min << endl;
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
    MaxMin2(A, n);
    return 0;
}