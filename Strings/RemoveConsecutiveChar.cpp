#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string removeConsecutiveCharacter(string S)
{
    string ans;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] != S[i + 1])
        {
            ans += S[i];
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << removeConsecutiveCharacter(s);
    return 0;
}