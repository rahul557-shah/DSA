//Balancing the paranthesis
#include <bits/stdc++.h>
using namespace std;
int isMatching(char ch1, char ch2)
{
    if (ch1 == '(' && ch2 == ')')
        return 1;
    else if (ch1 == '{' && ch2 == '}')
        return 1;
    else if (ch1 == '[' && ch2 == ']')
        return 1;
    else
        return 0;
}
bool ParanthesisCheck(string str)
{
    stack<char> stk;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            stk.push(str[i]);
        else
        {
            if (stk.empty())
                return false;
            else if (!isMatching(stk.top(), str[i]))
                return false;
            stk.pop();
        }
    }
    if (stk.empty())
        return true;
    else
        return false;
}
int main()
{
    string str1;
    cout << "Enter the string :";
    cin >> str1;
    if (ParanthesisCheck(str1))
        cout << "Paranthesis is balanced" << endl;
    else
        cout << "Paranthesis is not balanced" << endl;
    return 0;
}
