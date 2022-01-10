//Check if two given strings are rotations of each other
#include <bits/stdc++.h>
using namespace std;
bool areRotations(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    else
    {
        string temp = str1 + str1;
        if (temp.find(str2) != string::npos)
            return true;
        else
            return false;
    }
}

int main()
{
    string str1, str2;
    cout << "Enter the first string :";
    cin >> str1;
    cout << "Enter the second string :";
    cin >> str2;
    if (areRotations(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}
