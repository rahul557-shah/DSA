// Leader element in an array
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
// Time->O(n)
// Space->O(1)
vector<int> leaderElement(int A[], int n)
{
    vector<int> res;
    int i = n - 1;
    int leader = A[i];
    while (i >= 0)
    {
        if (A[i] >= leader)
        {
            res.push_back(A[i]);
            leader = A[i];
        }
        i--;
    }
    reverse(res.begin(), res.end());
    return res;
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
    vector<int> res;
    res = leaderElement(A, n);
    cout << "The Leader Elements are: " << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}