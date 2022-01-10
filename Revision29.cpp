//Climbing Staircase(Leetcode Q70)
#include <bits/stdc++.h>
using namespace std;
//Time->O(n)
//Space->O(1)
int climbStairs(int n)
{
    if (n <= 2)
        return n;
    int x = 1;
    int y = 2;
    for (int i = 3; i < n; i++)
    {
        int temp = y;
        y += x;
        x = temp;
    }
    return x + y;
}
int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;
    cout << "Number of ways to climb stairs is: " << climbStairs(n) << endl;
    return 0;
}