//Minimum number of flips in a binary string
#include <bits/stdc++.h>
using namespace std;
int MinFlips(string str)
{
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (i % 2 == 0 && str[i] == '1')
            c1++;
        if (i % 2 == 1 && str[i] == '0')
            c1++;
        if (i % 2 == 0 && str[i] == '0')
            c2++;
        if (i % 2 == 1 && str[i] == '1')
            c2++;
    }
    return min(c1, c2);
}
int main()
{
    string str1;
    cout << "Enter the string :";
    cin >> str1;
    cout << "Minimum number of flips is : " << MinFlips(str1) << endl;
    return 0;
}
