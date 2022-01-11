// Next Permutation of Numbers
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(n)
// Space->O(1)
void NextPermutation(vector<int> &A)
{
    int index = -1;
    int n = A.size();
    for (int i = n - 1; i > 0; i--)
    {
        if (A[i] > A[i - 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        reverse(A.begin(), A.end());
    else
    {
        int prev = index;
        for (int i = index + 1; i < n; i++)
        {
            if (A[i] > A[index - 1] && A[i] <= A[prev])
                prev = i;
        }
        swap(A[index - 1], A[prev]);
        reverse(A.begin() + index, A.end());
    }
}
// Time->O(n)
// Space->O(1)
void nextPermutation(vector<int> &A)
{
    int n = A.size();
    int i = n - 2;
    while (i >= 0 && A[i] >= A[i + 1])
        i--;
    if (i >= 0)
    {
        int j = n - 1;
        while (A[j] <= A[i])
            j--;
        swap(A[i], A[j]);
        reverse(A.begin() + i + 1, A.end());
    }
    else
        reverse(A.begin(), A.end());
}
int main()
{
    int n;
    vector<int> myvector;
    cout << "Enter the size: " << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        myvector.push_back(x);
    }
    cout << "Array is: " << endl;
    printArray(myvector);
    nextPermutation(myvector);
    cout << "Next Permutation is: " << endl;
    printArray(myvector);
    return 0;
}