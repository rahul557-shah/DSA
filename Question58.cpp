// Common elements among three sorted array
#include <bits/stdc++.h>
using namespace std;
// Time->O(n1+n2+n3)
// Space->O(n1+n2+n3)
vector<int> commonElement(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> res;
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    unordered_map<int, int> m3;

    for (int i = 0; i < n1; i++)
        m1[A[i]]++;
    for (int i = 0; i < n2; i++)
        m2[B[i]]++;
    for (int i = 0; i < n3; i++)
        m3[C[i]]++;
    for (int i = 0; i < n1; i++)
    {
        if (m1[A[i]] > 0 && m2[A[i]] > 0 && m3[A[i]] > 0)
        {
            res.push_back(A[i]);
            m1[A[i]] = 0;
        }
    }
    if (res.size() == 0)
        return {-1};
    else
        return res;
}
// Time->O(n1+n2+n3)
// Space->O(1)
vector<int> Common(int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> res;
    int i, j, k;
    i = j = k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            res.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j])
            i++;
        else if (B[j] < C[k])
            j++;
        else
            k++;
        int x = A[i - 1];
        int y = B[j - 1];
        int z = C[k - 1];
        while (x == A[i])
            i++;
        while (y == B[j])
            j++;
        while (z == C[k])
            k++;
    }
    if (res.size() == 0)
        return {-1};
    else
        return res;
}
int main()
{
    int n1, n2, n3;
    cout << "Enter the size of the first array: " << endl;
    cin >> n1;
    int A[n1];
    cout << "Enter the size of the second array: " << endl;
    cin >> n2;
    int B[n2];
    cout << "Enter the size of the third array: " << endl;
    cin >> n3;
    int C[n3];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> A[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\nEnter the elements: " << endl;
    for (int i = 0; i < n2; i++)
    {
        cin >> B[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < n2; i++)
    {
        cout << B[i] << " ";
    }
    cout << "\nEnter the elements: " << endl;
    for (int i = 0; i < n3; i++)
    {
        cin >> C[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < n3; i++)
    {
        cout << C[i] << " ";
    }
    cout << "\nThe Common Elements are :" << endl;
    vector<int> common;
    common = commonElement(A, B, C, n1, n2, n3);
    for (int i = 0; i < common.size(); i++)
    {
        cout << common[i] << " ";
    }

    return 0;
}