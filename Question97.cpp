//Check whether a string is a valid suffle of other two strings
#include <bits/stdc++.h>
using namespace std;
bool ValidSuffle(string str1, string str2, string res)
{
    int l1 = str1.length();
    int l2 = str2.length();
    int l3 = res.length();
    if ((l1 + l2) != l3)
        return false;
    else
    {
        int i, j, k;
        i = j = k = 0;
        int flag = 0;
        while (k < l3)
        {
            if (i < l1 && str1[i] == res[k])
                i++;
            else if (j < l2 && str2[j] == res[k])
                j++;
            else
            {
                flag = 1;
                break;
            }
            k++;
        }
        if (i < l1 || j < l2)
            return false;
        else
            return true;
    }
}

int main()
{
    string str1, str2, res;
    cout << "Enter the first string :";
    cin >> str1;
    cout << "Enter the second string :";
    cin >> str2;
    cout << "Enter the resultant string: ";
    cin >> res;
    if (ValidSuffle(str1, str2, res))
        printf("It is a valid suffle");
    else
        printf("Not a valid suffle");
    return 0;
}
