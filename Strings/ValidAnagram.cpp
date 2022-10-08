#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isAnagram(string s, string t)
{
    vector<int> a(26, 0);
    vector<int> b(26, 0);
    for (char c : s)
        a[c - 'a']++;
    for (char c : t)
        b[c - 'a']++;
    if (a == b)
        return true;
    return false;
}
int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    cout << isAnagram(s, t);
    return 0;
}