//Duplicates in an unsorted array
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
//Time->O(n)
//Space->O(n)
int Duplicates(int A[], int n)
{
    unordered_map<int, int> mymap;
    for (int i = 0; i < n; i++)
    {
        mymap[A[i]]++;
    }
    for (int i = 0; i < mymap.size(); i++)
    {
        if (mymap[i] > 1)
            return i;
    }
    return -1;
}
//Time->O(n)
//Space->O(1)
int FindDuplicates(int A[], int n)
{
    int slow = A[0];
    int fast = A[0];
    do
    {
        slow = A[slow];
        fast = A[A[fast]];
    } while (slow != fast);
    fast = A[0];
    while (slow != fast)
    {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
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
    cout << "The Duplicate number is: " << FindDuplicates(A, n) << endl;
    return 0;
}