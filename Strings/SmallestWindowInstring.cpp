#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given two strings S and P. Find the smallest window in the string S consisting of all
the characters(including duplicates) of the string P.  Return "-1" in case there
is no such window present. In case there are multiple such windows of same length,
 return the one with the least starting index.
 */

string smallestWindow(string s, string t)
{
    string ans = "";
    int n=s.length();
    unordered_map<char, int> map2;
    for (int k = 0; k < t.length(); k++)
        map2[t[k]]++;

    int matchCount = 0;
    int d_matchCount = t.length();
    unordered_map<char, int> map1;
    int i = -1;
    int j = -1;
    while (true)
    {
        bool f1 = false;
        bool f2 = false;
        // accquire
        while (i < (n-1) and matchCount < d_matchCount) 
        {
            i++;
            char ch = s[i];
            map1[s[i]]++;

            if (map1[s[ch]] <= map2[s[ch]])
                matchCount++;
            f1 = true;
        }

        while (j < i and matchCount == d_matchCount)
        {
            string temp = s.substr(j + 1, i + 1);
            if (ans.length() == 0 or temp.length() < ans.length())
                ans = temp;
            
            j++;
            char ch = s[j];
            
            if (map1[ch] == 1)
                map1.erase(ch);
            else
                map1[ch]--;

            if (map1[ch] < map2[ch])
                matchCount--;
            f2 = true;
        }
        if(f1==false and f2==false)
          break;
    }
    return ans;
}
int main()
{
    string s, p;
    cin >> s >> p;
    cout << smallestWindow(s, p);
    return 0;
}