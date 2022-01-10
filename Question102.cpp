//Check whether two strings are isomorphic or not
#include <bits/stdc++.h>
using namespace std;
bool Isomorphic(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    int map1[256] = {0};
    int map2[256] = {0};
    if (n != m)
        return false;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (!map1[str1[i]] && !map2[str2[i]])
            {
                map1[str1[i]] = str2[i];
                map2[str2[i]] = str1[i];
            }
            else if (map1[str1[i]] != str2[i])
                return false;
        }
    }
    return true;
}
int main()
{
    string str1, str2;
    cout << "Enter the first string :";
    cin >> str1;
    cout << "Enter the second string :";
    cin >> str2;
    if (Isomorphic(str1, str2))
        cout << "Yes two strings are Isomorphic" << endl;
    else
        cout << "Not an Isomorphic" << endl;
    return 0;
}
