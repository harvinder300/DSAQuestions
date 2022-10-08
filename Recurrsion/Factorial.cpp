#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int factorial(int n)
{  //It is mandatory to write return statement 
    if (n == 0)//Base Case
        return 1;
   
    return n * factorial(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}