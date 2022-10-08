#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given a sorted array and a value x,
the ceiling of x is the smallest element in an array greater than or equal to x,
 and the floor is the greatest element smaller than or equal to x.
 Assume that the array is sorted in non-decreasing order. Write efficient functions to find the floor and ceiling of x.
*/
int CeilSearch(vector<int> v, int low, int high, int x)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (v[mid] == x)
            return v[mid];
        else if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return v[low];
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
    cout << CeilSearch(v, 0, n - 1, k);
    return 0;
}