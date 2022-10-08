#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Find the majority element in the array. A majority
element in an array A[] of size n is an element that appears more than n/2 times
(and hence there is at most one such element).
*/
int MajorityElement(vector<int> v)
{
    int count = 0, res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (count == 0)
            res = v[i];
        if (res == v[i])
            count++;
        else
            count--;
    }
    count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == res)
            count++;
    }
    if (count > v.size() / 2)
        return res;
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int x;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cout << MajorityElement(v);
    return 0;
}