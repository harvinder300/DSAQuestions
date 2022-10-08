#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given a string s, return the longest palindromic substring in s.
*/
string expandFromMiddle(string s, int left, int right)
{
    if (s.empty() or left > right)
        return 0;
    while (left >= 0 and right < s.size() and s[left] == s[right])
    {
        left--;
        right++;
    }

    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s)
{
    if (s.length() <= 1)
        return s;

    string longest = "";
    for (int i = 0; i < s.length(); i++)
    {
        string len1 = expandFromMiddle(s, i, i);
        string len2 = expandFromMiddle(s, i, i + 1);
        string len3;
        if (len1.size() > len2.size())
            len3 = len1;
        else
            len3 = len2;
        if (len3.size() > longest.size())
        {
            longest = len3;
        }
    }
    return longest;
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}