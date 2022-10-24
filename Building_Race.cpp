#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        float a, b, x, y;
        cin >> a >> b >> x >> y;
        float chef = a / x;
        float chef_ina = b / y;
        if (chef > chef_ina)
            cout << "Chefina" << endl;
        else if (chef < chef_ina)
            cout << "Chef" << endl;
        else
            cout << "Both" << endl;
    }
    return 0;
}