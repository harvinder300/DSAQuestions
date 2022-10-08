#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void Print(string s)
{
    cout << "After Swapping = ";
    for (int i = 0; i < s.length(); i++)
        cout << s[i] << " ";
    cout << endl;
}
string Reverse(string &s, int i, int j)
{
    Print(s);
    if (i > j)
        return s;
    swap(s[i], s[j]);
    i++, j--;

    return Reverse(s, i, j);
}
int main()
{
    string s;
    cin >> s;
    int i = 0, j = s.length() - 1;
    cout << Reverse(s, i, j) << endl;

    return 0;
}