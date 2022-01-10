// Maximum Consecutive Ones(GFG)
#include <bits/stdc++.h>
using namespace std;
// Time->O(logn)
// Space->O(1)
int maxConsecutiveOnes(int N)
{
    int count = 0, maxCount = 0;
    while (N != 0)
    {
        if (N % 2 == 1)
            count++;
        else
            count = 0;
        maxCount = max(maxCount, count);
        N >>= 1;
    }
    return maxCount;
}
int main()
{
    int N;
    cout << "Enter a number: " << endl;
    cin >> N;
    cout << "Maximum Comsecutive ones is: " << maxConsecutiveOnes(N) << endl;
    return 0;
}