#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void SayDigit(int n)
{   //Base Case
    if (n == 0)
        return;
    //Processing Part
    int digit = n % 10;
    n = n / 10;
    SayDigit(n);
    //Printing
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    cout << arr[digit] << " ";
}
int main()
{
    int n;
    cin >> n;
    SayDigit(n);
    return 0;
}