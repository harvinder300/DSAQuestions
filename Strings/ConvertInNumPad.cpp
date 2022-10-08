#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string PrintSequence(string arr[], string output)
{
    string ans = "";
    int n = output.size();

    for (int i = 0; i < n; i++)
    {
        if (output[i] == ' ')
        {
            ans = ans + "0";
        }
        else
        {
            int pos = output[i] - 'A';

            ans = ans + arr[pos];
        }
    }
    return ans;
}
string Sequence(string s)
{
    string str[] = {"2", "22", "222",
                    "3", "33", "333",
                    "4", "44", "444",
                    "5", "55", "555",
                    "6", "66", "666",
                    "7", "77", "777", "7777",
                    "8", "88", "888",
                    "9", "99", "999", "9999"};

    return PrintSequence(str, s);
}
int main()
{
    string s;
    cin >> s;
  cout<<Sequence(s);
    return 0;
}