//Next Permutation of Numbers
#include <bits/stdc++.h>
using namespace std;
void NextPermutation(vector<int> &A)
{
    int index = -1;
    int n = A.size();
    for (int i = n - 1; i > 0; i--)
    {
        if (A[i] > A[i - 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        reverse(A.begin(), A.end());
    else
    {
        int prev = index;
        for (int i = index + 1; i < n; i++)
        {
            if (A[i] > A[index - 1] && A[i] <= A[prev])
                prev = i;
        }
        swap(A[index - 1], A[prev]);
        reverse(A.begin() + index, A.end());
    }
}
int main()
{
    std::vector<int> myvector = {1, 5, 8, 4, 7, 6, 5, 3, 1};
    NextPermutation(myvector);
    for (int i = 0; i < myvector.size(); i++)
        cout << myvector[i]<<",";
    return 0;
}