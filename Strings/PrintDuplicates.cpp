#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printDuplicates(string s)
{
    unordered_map<char, int> mp;
    for (auto i : s)
        mp[i]++;
    for (auto i : mp)
    {
        if (i.second > 1)
            cout << i.first << ", count = " << i.second<<endl;
    }
}
int main()
{
    string s;
    getline(cin, s);
    printDuplicates(s);
    return 0;
}