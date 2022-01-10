//Union of two sorted arrays
#include <bits/stdc++.h>
using namespace std;
//Counting the total number of elements
int Union(int A[], int B[], int m, int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < m; i++)
        map[A[i]]++;
    for (int i = 0; i < n; i++)
        map[B[i]]++;
    return map.size();
}
//Printing the Union
void PrintUnion(int A[], int B[], int m, int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < m; i++)
        map[A[i]]++;
    for (int i = 0; i < n; i++)
        map[B[i]]++;
    for (int i = 0; i < map.size(); i++)
    {
        if (map[i] != 0)
            printf("%d ", i);
    }
}
int main()
{
    int m, n, sum;
    cout << "Enter the size of first array: " << endl;
    cin >> m;
    cout << "Enter the size of second array: " << endl;
    cin >> n;
    int A[m], B[n];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\nEnter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    cout << "The array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
    printf("\nTotal number of elements after union is: %d", Union(A, B, m, n));
    printf("\n");
    PrintUnion(A,B,m,n);
    return 0;
}
