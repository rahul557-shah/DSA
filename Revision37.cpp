//Palindrome Number(Leetcode Q9)
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int n)
{
    if (n == 0)
        return true;
    if (n < 0 || n % 10 == 0)
        return false;
    int rev_num = 0;
    while (n > rev_num)
    {
        int rem = n % 10;
        n = n / 10;
        rev_num = (rev_num * 10) + rem;
    }
    if (n == rev_num || n == rev_num / 10)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    if (isPalindrome(n))
        cout << "Yes the number is palindrome!!" << endl;
    else
        cout << "Not a Palindrome number!!" << endl;
    return 0;
}