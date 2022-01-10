//Pow(x,n)[Leetcode Q50]
#include <bits/stdc++.h>
using namespace std;
//Time->O(n)
//Space->O(1)
double Power(double x, int n)
{
    if (n < 0)
        n = n * (-1.0);
    double ans = 1.0;
    for (int i = 0; i < n; i++)
    {
        ans = ans * x;
    }
    if (n < 0)
        ans = double(1.0) / double(ans);
    return ans;
}
//Time->O(logn)
//Space->O(1)
double PowerOptimal(double x, int n)
{
    if (n < 0)
        n = n * (-1.0);
    int num = n;
    double ans = 1.0;
    while (num > 0)
    {
        if (num % 2)
        {
            ans = ans * x;
            num = num - 1;
        }
        else
        {
            x = x * x;
            num = num / 2;
        }
    }
    if (n < 0)
        ans = double(1.0) / double(ans);
    return ans;
}
int main()
{
    double x;
    int n;
    cout << "Enter the number and power:" << endl;
    cin >> x >> n;
    cout << "The power of given number is: " << PowerOptimal(x, n) << endl;
    return 0;
}