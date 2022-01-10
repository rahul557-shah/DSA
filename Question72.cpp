//Arrange positive and negative elements alternately with O(1) space
#include <bits/stdc++.h>
using namespace std;
//Order of the elements arenot preserved
//Time->O(n)
//Space->O(1)
void Rearrange(int A[], int n)
{
    int l, r;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        if (A[l] > 0 && A[r] < 0)
        {
            l++;
            r--;
        }
        else if (A[l] < 0 && A[r] > 0)
        {
            swap(A[l], A[r]);
            l++;
            r--;
        }
        else if (A[l] > 0)
            l++;
        else if (A[r] < 0)
            r--;
    }
    int k = 0;
    while (k < n && l < n)
    {
        swap(A[k], A[l]);
        l++;
        k = k + 2;
    }
}
//Preserving the order
//Time->O(n^2)
//Space->O(1)
void RightRotate(int A[], int from, int to)
{
    int temp = A[to];
    for (int i = to; i > from; i--)
        A[i] = A[i - 1];
    A[from] = temp;
}
void ReOrder(int A[], int n)
{
    int wrongIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (wrongIndex != -1)
        {
            if ((A[wrongIndex] < 0 && A[i] >= 0) || A[wrongIndex] >= 0 && A[i] < 0)
            {
                RightRotate(A, wrongIndex, i);
                if (i - wrongIndex >= 2)
                    wrongIndex += 2;
                else
                    wrongIndex = -1;
            }
        }
        else
        {
            if ((A[i] < 0 && i % 2 == 1) || (A[i] >= 0 && i % 2 == 0))
                wrongIndex = i;
        }
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
    ReOrder(A, n);
    cout << "\nAfter Rearranging the array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}