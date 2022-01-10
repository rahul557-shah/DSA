//Find the elements that occurs more than n/k times
#include <bits/stdc++.h>
using namespace std;
//Time->O(nlogn)
//Space->O(1)
void findElement(int A[], int n, int k)
{
    int x = n / k;
    sort(A, A + n);
    for (int i = 0; i < n;)
    {
        int cnt = 1;
        while ((i + 1) < n && A[i] == A[i + 1])
        {
            cnt++;
            i++;
        }
        if (cnt > x)
        {
            cout << A[i] << " ";
        }
        i++;
    }
}
//Time->O(n)
//Space->O(n)
void FindElement(int A[], int n, int k)
{
    int x = n / k;
    unordered_map<int, int> mymap;
    for (int i = 0; i < n; i++)
    {
        mymap[A[i]]++;
    }
    for (int i = 0; i < mymap.size(); i++)
    {
        if (mymap[i] > x)
            cout << i << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int A[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    int k;
    cout << "\nEnter the value of k:";
    cin >> k;
    cout << "The elements are: " << endl;
    findElement(A, n, k);
    return 0;
}