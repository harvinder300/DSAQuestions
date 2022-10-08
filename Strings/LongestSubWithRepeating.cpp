#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given a string s, find the length of the longest substring without repeating characters.

*/
int lengthOfLongestSubstring(string s)
{

    int n = s.length();
    int res = 0;
    vector<int> prev(256, -1);
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, prev[s[j]] + 1);
        int max_end = j - i + 1;
        res = max(res, max_end);
        prev[s[j]] = j;
    }
    return res;
}
int main()
{
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s);
    return 0;
}