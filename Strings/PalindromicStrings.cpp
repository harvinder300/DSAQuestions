#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int expandFromMiddle(string s, int left, int right)
{  //Program to give Palindromic strings
    int ans = 0;
    if (s.empty() or left > right)
        return 0;
    while (left >= 0 and right <= s.size() and s[left] == s[right])
    {
        ans++;
        left--;
        right++;
    }

    return ans;
}

int countSubstrings(string s)
{
    if (s.length() < 1)
        return 0;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        count += expandFromMiddle(s, i, i);
        count += expandFromMiddle(s, i, i + 1);
    }
    return count;
}
int main()
{
    string s;
    cin >> s;
    cout << countSubstrings(s);
    return 0;
}