#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                cnt++;
            else
                break;
        }
        cout << cnt << endl;
    }
    return 0;
}