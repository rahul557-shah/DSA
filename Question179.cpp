// Union and Intersection between two arrays
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
pair<int, int> IntersectionUnion(vector<int> A, vector<int> B, int m, int n)
{
    int common = 0, union1 = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (A[i] > B[j])
        {
            union1++;
            j++;
        }
        else if (A[i] < B[j])
        {
            union1++;
            i++;
        }
        else
        {
            union1++;
            common++;
            i++;
            j++;
        }
    }
    while (i < m)
    {
        union1++;
        i++;
    }
    while (j < n)
    {
        union1++;
        j++;
    }
    return {common, union1};
}
// Time->O(n)
// Space->O(n)
pair<int, int> UnionIntersection(vector<int> A, vector<int> B, int m, int n)
{
    unordered_map<int, int> mymap;
    int union1 = 0, common = 0;
    for (int i = 0; i < m; i++)
        mymap[A[i]]++;
    for (int i = 0; i < n; i++)
        mymap[B[i]]++;
    union1 = mymap.size();
    for (int i = 0; i < m; i++)
    {
        if (mymap[A[i]] > 1)
        {
            common++;
            mymap[A[i]] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (mymap[B[i]] > 1)
        {
            common++;
            mymap[B[i]] = 0;
        }
    }
    return make_pair(union1, common);
}
int main()
{
    vector<int> A, B;
    int m, n;
    cout << "Enter the size: " << endl;
    cin >> m >> n;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        B.push_back(x);
    }
    cout << "The First Array is: " << endl;
    printArray(A);
    cout << "The Second Array is: " << endl;
    printArray(B);
    pair<int, int> res;
    res = UnionIntersection(A, B, m, n);
    cout << res.first << " " << res.second << endl;
    return 0;
}