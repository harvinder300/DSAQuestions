#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool CheckPalindrome(string &s, int i, int j)
{
    if (s[i] != s[j])
        return false;
    if (s[i] == s[j])
        return true;

    i++, j--;
    return CheckPalindrome(s, i, j);
}
int main()
{
    string s;
    cin >> s;
    int i = 0, j = s.length() - 1;
    if (CheckPalindrome(s, i, j))
        cout << "Palindrome" << endl;
    else
        cout << "Not a Palindrome" << endl;

    return 0;
}
