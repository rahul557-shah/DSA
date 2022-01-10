//Intersection of two arrays II (Leetcode Q350)
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
//Time->O(m+n)
//Space->O(min(m,n))
vector<int> IntersectionofArrays(int A[], int m, int B[], int n)
{
    unordered_map<int, int> mymap;
    vector<int> ans;
    for (int i = 0; i < m; i++)
        mymap[A[i]]++;
    for (int i = 0; i < n; i++)
    {
        if (mymap[B[i]] > 0)
        {
            ans.push_back(B[i]);
            mymap[B[i]]--;
        }
    }
    return ans;
}
int main()
{
    int m, n;
    cout << "Enter the size of both arrays" << endl;
    cin >> m >> n;
    int A[m], B[n];
    cout << "Enter the elements in first array: " << endl;
    for (int i = 0; i < m; i++)
        cin >> A[i];
    cout << "The first array is: " << endl;
    printArray(A, m);
    cout << "Enter the elements in second array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> B[i];
    cout << "The second array is: " << endl;
    printArray(B, n);
    vector<int> res;
    cout << "Intersection of the arrays is: " << endl;
    res = IntersectionofArrays(A, m, B, n);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}