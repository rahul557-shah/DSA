//Chocolate Distribution Problem
#include <bits/stdc++.h>
using namespace std;
int ChocolateDist(int A[], int n, int m)
{
    int min = INT_MAX;
    sort(A, A + n);
    for (int i = 0; (i + m - 1) < n; i++)
    {
        int diff = A[i + m - 1] - A[i];
        if (diff < min)
            min = diff;
    }
    return min;
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
    int m;
    cout << "\nEnter the number of students" << endl;
    cin >> m;
    cout << "The Minimum difference is:" << ChocolateDist(A, n, m) << endl;
    return 0;
}