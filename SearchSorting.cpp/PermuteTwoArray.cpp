#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given two arrays of equal size n and an integer k. The task is to permute both arrays such that sum of their corresponding element
is greater than or equal to k i.e a[i] + b[i] >= k. The task is print “Yes” if any such permutation exists, otherwise print “No”.
*/

bool isPossible(vector<int> v, vector<int> a, int k)
{
    sort(v.begin(), v.end());
    sort(a.begin(),a.end(),greater<int>());

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] + a[i] < k)
            return false;
    }
    return true;
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
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    int k;
    cin >> k;
    cout << isPossible(v, a, k);
    return 0;
}