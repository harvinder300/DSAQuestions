#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given an array a[]
of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.
*/
vector<int> duplicates(int arr[], int n)
{
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % size] = arr[arr[i] % size] + size;
    }

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= size * 2)
        {
            res.push_back(i);
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    int x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> v = duplicates(a, n);
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}