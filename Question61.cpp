//Array Subset of another array
#include <bits/stdc++.h>
using namespace std;
//Time->O(mlogm+nlogn)
//Space->O(1)
bool Subset(int A[], int m, int B[], int n)
{
    int i, j;
    i = j = 0;
    sort(A, A + m);
    sort(B, B + n);
    if (m < n)
        return 0;
    while (i < m && j < n)
    {
        if (A[i] == B[j])
        {
            i++;
            j++;
        }
        else if (A[i] < B[j])
            i++;
        else
            return 0;
    }
    if (j == n)
        return true;
    else
        return false;
}
//Time->O(n)
//Space->O(n)
bool isSubset(int A[], int m, int B[], int n)
{
    unordered_map<int, int> mymap;
    for (int i = 0; i < m; i++)
    {
        mymap[A[i]]++;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (mymap[B[i]])
            count++;
    }
    if (count == n)
        return true;
    else
        return false;
}
int main()
{
    int m, n;
    cout << "Enter the size of first array: " << endl;
    cin >> m;
    int A[m];
    cout << "Enter the size of second array: " << endl;
    cin >> n;
    int B[n];
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
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
    if (isSubset(A, m, B, n))
        cout << "\nYes it is a subset!!" << endl;
    else
        cout << "\nNot  a subset!!" << endl;
    return 0;
}