// Square root of a number
#include <bits/stdc++.h>
using namespace std;
// Time->O(logn)
// Space->O(1)
int squareRoot(int x)
{
    int low = 1, high = x, result = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid * mid == x)
            return mid;
        else if (mid * mid > x)
            high = mid - 1;
        else
        {
            low = mid + 1;
            result = mid;
        }
    }
    return result;
}
int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    cout << "Square Root is: " << squareRoot(n) << endl;
    return 0;
}