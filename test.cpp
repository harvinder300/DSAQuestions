#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string solve(string a, string b)
{
    /* map<char, int> mp1;
      map<char, int> mp2;

      for (int i = 0; i < a.size(); i++)
      {
          mp1[a[i]] = i;
      }
      for (int i = 0; i < b.size(); i++)
      {
          mp2[b[i]] = i;
      }*/
    string res = "";
    int k = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j] and (i == j and (i - 1) == 1))
            {
                res += a[i];
            }
        }
    }
    return res;
}
int main()
{
    string a, b;
    cin >> a >> b;
    cout << solve(a, b);
}