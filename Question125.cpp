//Product Array Puzzle
#include <bits/stdc++.h>
using namespace std;
//Time->O(n)
//Space->O(n)
void ProductOfAll(int A[], int n)
{
    int left[n];
    int right[n];
    left[0] = 1;
    right[n - 1] = 1;
    for (int i = 1; i < n; i++)
        left[i] = left[i - 1] * A[i - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = right[i + 1] * A[i + 1];
    for (int i = 0; i < n; i++)
        A[i] = left[i] * right[i];
}
//Time->O(n)
//Space->O(1)
void ProductAll(int A[], int n)
{
    int product = 1;
    int result[n];
    for (int i = 0; i < n; i++)
    {
        product = product * A[i];
        result[i] = product;
    }
    product = 1;
    for (int i = n - 1; i > 0; i--)
    {
        result[i] = result[i - 1] * product;
        product = product * A[i];
    }
    result[0] = product;
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
}
int main()
{
    int n;
    cout << "Enter the size of array::";
    cin >> n;
    int A[n], i;
    cout << "Enter the elements " << endl;
    for (i = 0; i < n; i++)
        cin >> A[i];
    cout << "Elements of the array\n";
    for (i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\nProduct of all elements is: " << endl;
    ProductAll(A, n);
    return 0;
}