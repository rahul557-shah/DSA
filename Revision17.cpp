//Two Sum(LEETCODE Q1)
#include <bits/stdc++.h>
using namespace std;
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
}
//Time->O(n^2)
//Space->O(1)
void TwoSum(int A[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (target - A[i] == A[j])
            {
                cout << i << "," << j << endl;
                break;
            }
        }
    }
}
//Time->O(n)
//Space->O(n)
vector<int> TwoSums(int A[], int n, int target)
{
    vector<int> ans;
    unordered_map<int, int> mymap;
    for (int i = 0; i < n; i++)
    {
        if (mymap.find(target - A[i]) != mymap.end())
        {
            ans.push_back(mymap[target - A[i]]);
            ans.push_back(i);
            return ans;
        }
        else
            mymap[A[i]] = i;
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size" << endl;
    cin >> n;
    int A[n];
    vector<int> res;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "The array is: " << endl;
    printArray(A, n);
    int target;
    cout << "Enter the target " << endl;
    cin >> target;
    ///TwoSum(A, n, target);
    res = TwoSums(A, n, target);
    cout << "Index of two sum number is: " << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}