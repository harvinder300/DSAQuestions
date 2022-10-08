#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> nextPermutation(int N, vector<int> arr)
{
    int n = arr.size(), k, l;

    for (k = n - 2; k >= 0; k--)
    {
        if (arr[k] < arr[k + 1])
            break;
    }
    if (k < 0)
    
        reverse(arr.begin(), arr.end());
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (arr[l] > arr[k])
                break;
        }
        swap(arr[k], arr[l]);
        reverse(arr.begin() + k + 1, arr.end());
    }
    return arr;
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
    v = nextPermutation(n, v);
    for (auto i : v)
        cout << i << " ";
    return 0;
}