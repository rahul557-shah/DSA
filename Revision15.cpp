//Next Permutation of a Number
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << "\n";
}
//Time->O(n)
//Space->O(1)
void NextPermutation(vector<int> &A)
{
    int n = A.size();
    int index = -1;
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
        swap(A[index-1], A[prev]);
        reverse(A.begin() + index, A.end());
    }
}
int main()
{
    int n, x;
    vector<int> A;
    cout << "Enter the size" << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        A.push_back(x);
    }
    cout << "The Original Permutation is: " << endl;
    printArray(A);
    cout << "The Next Permutation is: " << endl;
    NextPermutation(A);
    printArray(A);
    return 0;
}