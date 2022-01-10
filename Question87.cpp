//Sort an array in wave form
#include <bits/stdc++.h>
using namespace std;
void SortWave(int A[], int n)
{
    sort(A, A + n);

    for (int i = 0; i < n - 1; i += 2)
    {
        swap(A[i], A[i + 1]);
    }
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
    SortWave(A, n);
    cout << "\nAfter Sorting In WaveForm:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}