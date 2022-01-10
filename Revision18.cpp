//Best Time to Buy and Sell the Stock
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
int BuySellStock(int A[], int n)
{
    int mini = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, A[i]);
        maxProfit = max(maxProfit, A[i] - mini);
    }
    return maxProfit;
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
    cout << "Maximum Profit is: " << BuySellStock(A, n) << endl;
    return 0;
}