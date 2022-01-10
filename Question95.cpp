// Count all the duplicates in a string
#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
    map<char, int> count;
    for (int i = 0; i < str.length(); i++)
        count[str[i] - 97]++;

    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] > 1)
            cout << char(i + 97) << ","
                 << "count->" << count[i] << endl;
    }
}
int main()
{
    string str;
    cout << "Enter a string : ";
    cin >> str;
    printDups(str);
    return 0;
}
