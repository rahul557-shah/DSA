// Recursion on Subsequences
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(2^n)
// Space->O(n)
void printSubsequences(int index, vector<int> &A, vector<int> res)
{
    if (index >= A.size())
    {
        for (auto itr : res)
            cout << itr << " ";
        if (res.size() == 0)
            cout << "{}";
        cout << endl;
        return;
    }
    printSubsequences(index + 1, A, res);
    res.push_back(A[index]);
    printSubsequences(index + 1, A, res);
    res.pop_back();
}
int main()
{
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    vector<int> A(n);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "Array is: " << endl;
    printArray(A);
    vector<int> res;
    printSubsequences(0, A, res);
    return 0;
}