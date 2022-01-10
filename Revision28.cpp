//Count all the pairs with a given sum
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
int countPairs(int A[], int n, int sum)
{
    int count = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x = sum - A[i];
        if (m[x] == 0)
            m[A[i]]++;
        else
        {
            count += m[x];
            m[A[i]]++;
        }
    }
    return count;
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
    int sum;
    cout << "Enter the sum: " << endl;
    cin >> sum;
    cout << "Total number of pairs is: " << countPairs(A, n, sum) << endl;
    return 0;
}