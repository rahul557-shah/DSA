// Print all subsequences whose sum is 'K'(Recursion)
// Print any one subsequences whose sum is 'K'(Recursion)
// Count subsequences whose sum is 'K'(Recursion)
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(2^n)
// Space->O(n)+O(n)
void allSubsequences(int index, int sum, int k, int n, vector<int> &A, vector<int> &temp)
{
    if (index == n)
    {
        if (sum == k)
        {
            for (auto itr : temp)
                cout << itr << " ";
            cout << endl;
        }
        return;
    }
    temp.push_back(A[index]);
    sum += A[index];

    allSubsequences(index + 1, sum, k, n, A, temp);

    temp.pop_back();
    sum -= A[index];

    allSubsequences(index + 1, sum, k, n, A, temp);
}
// Time->O(2^n)
// Space->O(n)
bool anyOneSubsequences(int index, int sum, int k, int n, vector<int> &A)
{
    if (index == n)
    {
        if (sum == k)
        {
            for (auto itr : A)
                cout << itr << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    sum += A[index];
    if (anyOneSubsequences(index + 1, sum, k, n, A))
        return true;
    sum -= A[index];
    if (anyOneSubsequences(index + 1, sum, k, n, A))
        return true;
    return false;
}
// Time->O(2^n)
// Space->O(n)
int countSubsequences(int index, int sum, int k, int n, vector<int> &A)
{
    if (index == n)
    {
        if (sum == k)
            return 1;
        return 0;
    }
    sum += A[index];
    int left = countSubsequences(index + 1, sum, k, n, A);

    sum -= A[index];
    int right = countSubsequences(index + 1, sum, k, n, A);
    return left + right;
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
    int k;
    cout << "Enter the sum: " << endl;
    cin >> k;
    vector<int> temp;
    int sum = 0;
    cout << "Total number of subsequences with sum K is: " << countSubsequences(0, sum, k, n, A);
    // anyOneSubsequences(0, sum, k, n, A);
    return 0;
}