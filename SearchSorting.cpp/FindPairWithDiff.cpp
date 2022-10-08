#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given an unsorted array and a number n,
find if there exists a pair of elements in the array whose difference is n.
*/
bool findPair(vector<int> v, int k)
{
    sort(v.begin(), v.end());

    int low = 0;
    int high = 1;
    k = abs(k);
    while (low <= high and high < v.size())
    {
        int diff = v[high] - v[low];
        if (diff == k and low != high)
            return true;
        else if (diff > k)
            low++;
        else
            high++;
    }
    return false;
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
    int k;
    cin >> k;
    cout << findPair(v, k);
    return 0;
}