// Rakshya Bandhan Problem
#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
// Time->O(nlogn)
// Space->O(1)
int rakshaBandhan(vector<int> arr)
{
    int n = arr.size();
    int sum = 0, count = 0;
    int i = n - 1;
    sort(arr.begin(), arr.end());
    while (i >= 0)
    {
        sum += arr[i];
        if (sum <= 0)
            break;
        count++;
        i--;
    }
    return count;
}
int main()
{
    vector<int> A;
    int n;
    cout << "Enter the size: " << endl;
    cin >> n;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << "The Array is: " << endl;
    printArray(A);
    cout << "Maximum number of Rakhi is: " << rakshaBandhan(A) << endl;
    return 0;
}