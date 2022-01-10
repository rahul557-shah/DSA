//Find all the dupicates from an array(Leetcode Q442)
//1<=A[i]<=n
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
//Time->O(n)
//Space->O(1)
vector<int> FindAllDuplicates(int A[], int n)
{
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int index = abs(A[i]) - 1;
        if (A[index] > 0)
            A[index] = -A[index];
        else
            res.push_back(index + 1);
    }
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
    res = FindAllDuplicates(A, n);
    cout << "The Duplicate numbers are: " << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}