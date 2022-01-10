// Majority Element II(Leetcode Q229)
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
    if (max > n / 3)
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
        if (m[A[i]] > n / 3)
        {
            return A[i];
        }
    }
    return -1;
}
// Time->O(n)
// Space->O(1)
// Boyer Moore's Algorithm
vector<int> MajorityOptimised(int A[], int n)
{
    int num1 = -1, num2 = -1;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == num1)
            c1++;
        else if (A[i] == num2)
            c2++;
        else if (c1 == 0)
        {
            num1 = A[i];
            c1 = 1;
        }
        else if (c2 == 0)
        {
            num2 = A[i];
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    vector<int> res;
    c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == num1)
            c1++;
        if (A[i] == num2)
            c2++;
    }
    if (c1 > n / 3)
        res.push_back(num1);
    if (c2 > n / 3)
        res.push_back(num2);
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
    cout << "Majority Element is: " << endl;
    res = MajorityOptimised(A, n);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}