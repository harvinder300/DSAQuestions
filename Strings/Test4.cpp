#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string removeChar(string a, string b)
{
    for (auto i : b)
    {
        // we find char exit or not
        while (find(a.begin(), a.end(), i) != a.end())
        {
            auto itr = find(a.begin(), a.end(), i);
            // if char exit we simply remove that char
            a.erase(itr);
        }
    }
    return a;
}
int main()
{
    string a, b;
    cin >> a >> b;
    cout << removeChar(a, b);
    return 0;
}