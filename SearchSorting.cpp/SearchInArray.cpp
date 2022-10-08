#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
Searching in an array where adjacent differ by at most k

A step array is an array of integers where each element has a difference of at most k with its neighbor.
 Given a key x, we need to find the index value of x if multiple-element exist to return the first occurrence
 of the key.
*/
int FindElement(vector<int> v, int k, int x)
{
    int n = v.size();

    int i = 0;
    while (i < n)
    {
        if (v[i] == x)
            return i;
        int diff = v[i] - x;
        int ans = abs(diff / k);
        i = i + max(1, ans);
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int z;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> z;
        v.push_back(z);
    }
    int k, x;
    cin >> k >> x;
    cout << FindElement(v, k, x);
    return 0;
}