// Majority Element
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
// Time->O(n^2)
// Space->O(1)
int Majority(int A[], int n)
{
    int index = -1;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (A[i] == A[j])
                count++;
        }
        if (count > max)
        {
            max = count;
            index = i;
        }
    }
    if (max > n / 2)
        return A[index];
    else
        return -1;
}
// Time->O(n)
// Space->O(n)
int MajorityElement(int A[], int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[A[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (m[A[i]] > n / 2)
        {
            return A[i];
        }
    }
    return -1;
}
// Time->O(n)
// Space->O(1)
int MajorityOptimised(int A[], int n)
{
    int count = 0;
    int candidate = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            candidate = A[i];
        if (A[i] == candidate)
            count++;
        else
            count--;
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == candidate)
            c++;
    }
    if (c > n / 2)
        return candidate;
    else
        return -1;
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
    cout << "Majority Element is: " << MajorityOptimised(A, n) << endl;
    return 0;
}