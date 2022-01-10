//Move Negative numbers to one side(forward)
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
//Order is not maintained
//Time->O(n)
void Rearrange1(int A[], int n)
{
    int l = 0, h = n - 1;
    while (l < h)
    {
        if (A[l] > 0)
        {
            swap(A[l], A[h]);
            h--;
        }
        else
            l++;
    }
}
//Order of negative numbers is preserved
void Rearrange2(int A[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
        {
            if (i != j)
                swap(A[i], A[j]);
            j++;
        }
    }
}
//Order is maintained
//Time->O(n)
//Space->O(n)
void Rearrange3(int A[], int n)
{
    int temp[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
            temp[j++] = A[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] >= 0)
            temp[j++] = A[i];
    }
    for (int i = 0; i < n; i++)
        A[i] = temp[i];
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
    Rearrange3(A, n);
    cout << "After Swapping negative and positive numbers: " << endl;
    printArray(A, n);
    return 0;
}