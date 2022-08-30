#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
vector<int> removeDuplicates(vector<int> &A, int n)
{
    int i = 0, j = 1;
    while (j < n)
    {
        if (A[i] == A[j])
            j++;
        else
        {
            i++;
            A[i] = A[j];
        }
    }
    int sz = i + 1;
    vector<int> temp(sz);
    for (int i = 0; i < sz; i++)
        temp[i] = A[i];
    return temp;
}
int main()
{
    int n;
    cout << "Enter size: " << endl;
    cin >> n;
    vector<int> A(n);
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "Original Array is: " << endl;
    printArray(A, n);
    vector<int> ans = removeDuplicates(A, n);
    cout << "After Removing Duplicates Array is: " << endl;
    printArray(ans, ans.size());
    return 0;
}