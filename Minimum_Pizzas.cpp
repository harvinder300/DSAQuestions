#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int slices = n * x;
        if (slices % 4 == 0)
            cout << (slices / 4)<<endl;
        else
            cout << ((slices / 4) + 1)<<endl;
    }
    return 0;
}