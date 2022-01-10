//Median of two Sorted Arrays for both equal and different sizes
#include <bits/stdc++.h>
using namespace std;
//Time->O(n)
double MedianOfSorted(int A[], int n1, int B[], int n2)
{
    if (n2 < n1)
        return MedianOfSorted(B, n2, A, n1);
    int low = 0;
    int high = n1;
    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;
        int left1 = cut1 == 0 ? INT_MIN : A[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : B[cut2 - 1];
        int right1 = cut1 ==n1 ? INT_MAX : A[cut1];
        int right2 = cut2 == n2 ? INT_MAX : B[cut2];
        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0;
}
int main()
{
    int m, n;
    cout << "Enter the size of first array: " << endl;
    cin >> m;
    int A[m];
    cout << "Enter the size of second array: " << endl;
    cin >> n;
    int B[n];
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
    cout << "\nMedian of two sorted Arrays is: " << MedianOfSorted(A, m, B, n) << endl;
    return 0;
}