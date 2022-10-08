#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool valid(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}
bool isPalindrome(string s)
{
    string x;
    for (int i = 0; i < s.size(); i++)
    {
        if (valid(s[i]))
            x.push_back(s[i]);
    }
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    int st = 0, e = x.size() - 1;

    while (st <= e)
    {
        if (x[st] != x[e])
            return false;
        else
        {
            st++;
            e--;
        }
    }
    return true;
}
int main()
{
    string s;
    cin >> s;
    cout << isPalindrome(s);
    return 0;
}