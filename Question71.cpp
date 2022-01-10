//Minimum and Maximum Elements in an array with minmum number of comparisons
#include <bits/stdc++.h>
using namespace std;
//No of comparisons ->2*(n-2)+1
void MaxAndMin(int A[], int n)
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
        for (int i = 2; i < n; i++)
        {
            if (A[i] > max)
                max = A[i];
            if (A[i] < min)
                min = A[i];
        }
    }
    cout << "\nMaximum elements is: " << max << endl;
    cout << "Minimum Element is: " << min << endl;
}
//Number of comparisons:
//Odd->3*(n-1)/2
//Even->1+(n-2)/2
void MaxMin(int A[], int n)
{
    int min, max;
    int i;
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
        max = min = A[0];
        i = 1;
    }
    while (i < n - 1)
    {
        if (A[i] > A[i + 1])
        {
            if (A[i] > max)
                max = A[i];
            if (A[i + 1] < min)
                min = A[i];
        }
        else
        {
            if (A[i + 1] > max)
                max = A[i + 1];
            if (A[i] < min)
                min = A[i];
        }
        i = i + 2;
    }
    cout << "\nMaximum elements is: " << max << endl;
    cout << "Minimum Element is: " << min << endl;
}
int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    MaxMin(A, n);
    return 0;
}