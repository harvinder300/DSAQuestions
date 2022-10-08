#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*int Power(int a, int b)
{
    if (b == 0)
        return 1;
    if (a == 0)
        return a;
    int ans = Power(a, b / 2);
    if (b % 2 == 0)
        return ans * ans;
    else
        return ans * ans * a;
}*/
double Power(double a, int b)
{
    if (b == 0)
        return 1;
    /*if (a == 0)
        return a;*/
    if(b<0)
    {
        b=abs(b);
        a=1/a;
    }
    double ans = Power(a, b / 2);
    if (b % 2 == 0)
        return ans * ans;
    else
        return ans * ans * a;
}
int main()
{
    double a;
    int b;
    cin >> a;
    cin>>b;
    double ans= Power(a, b);
    cout<<ans;
    return 0;
}