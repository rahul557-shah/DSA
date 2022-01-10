// Tapping Water Problem
#include <bits/stdc++.h>
using namespace std;
// Time->O(n^2)
// Space->O(1)
int maxTapWater(int A[], int n)
{
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int left = A[i];
        for (int j = 0; j < i; j++)
            left = max(left, A[j]);

        int right = A[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, A[j]);
        ans += min(right, left) - A[i];
    }
    return ans;
}
// Time->O(n)
// Space->O(n)
int Tapwater(int A[], int n)
{
    int ans = 0;
    int max1, max2;
    int left[n], right[n];
    max1 = left[0] = A[0];
    max2 = right[n - 1] = A[n - 1];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > max1)
            max1 = A[i];
        left[i] = max1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] > max2)
            max2 = A[i];
        right[i] = max2;
    }
    for (int i = 0; i < n; i++)
        ans += min(left[i], right[i]) - A[i];
    return ans;
}
// Time->O(n)
// Space->O(1)
int trapWater(int A[], int n)
{
    int left = 0, right = n - 1;
    int leftmax = 0, rightmax = 0;
    int ans = 0;
    while (left <= right)
    {
        if (A[left] <= A[right])
        {
            if (A[left] >= leftmax)
                leftmax = A[left];
            else
                ans += leftmax - A[left];
            left++;
        }
        else
        {
            if (A[right] >= rightmax)
                rightmax = A[right];
            else
                ans += rightmax - A[right];
            right--;
        }
    }
    return ans;
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
    cout << "\nTapwater is: " << trapWater(A, n) << endl;
    return 0;
}