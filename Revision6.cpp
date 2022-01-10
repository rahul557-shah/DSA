//Rearrange alternate positive and negative elements in an array
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
void Rearrange(int A[], int n)
{
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
        if (A[i] >= 0)
        {
            pos.push_back(A[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0)
        {
            neg.push_back(A[i]);
        }
    }
    int i = 0;
    int k = 0, j = 0;
    while (i < n)
    {
        if (j < pos.size())
        {
            A[i] = pos[j];
            i++;
            j++;
        }
        if (k < neg.size())
        {
            A[i] = neg[k];
            i++;
            k++;
        }
    }
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
    cout << "After Rearranging :" << endl;
    Rearrange(A, n);
    printArray(A, n);
    return 0;
}