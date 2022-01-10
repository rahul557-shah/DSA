//Minimum number of jumps to reach the end
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
int MinJumps(int A[], int n)
{
    int maxR = A[0];
    int jump = 1;
    int step = A[0];
    if (n == 1)
        return 0;
    else if (A[0] == 0)
        return -1;
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jump;
            maxR = max(maxR, A[i] + i);
            step--;
            if (step == 0)
            {
                jump++;
                if (i >= maxR)
                    return -1;
                step = maxR - i;
            }
        }
    }
    return 0;
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
    cout << "Minimum number of jumps is: " << MinJumps(A, n) << endl;
    return 0;
}