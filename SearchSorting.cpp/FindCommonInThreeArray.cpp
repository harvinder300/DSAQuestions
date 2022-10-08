#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given three arrays sorted in non-decreasing order, print all common elements in these arrays.
*/

vector<int> FindCommon(vector<int> v, vector<int> z, vector<int> r)
{
    int i = 0, j = 0, k = 0;
    int x, y, q;
    x = v[i];
    y = z[i];
    q = r[i];
    vector<int> ans;
    vector<int>::iterator it;
    while (i < v.size() and j < z.size() and k < r.size())
    {
        if (v[i] == z[j] and z[j] == r[k])
        {
            it = find(ans.begin(), ans.end(), v[i]);//To Handle Duplicates
            if (it == ans.end())
                ans.push_back(v[i]);
            i++;
            j++;
            k++;
        }

        else if (v[i] < z[j])
            i++;
        else if (z[j] < r[k])
            j++;
        else
            k++;
    }
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
    int m;
    cin >> m;
    vector<int> z;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        z.push_back(x);
    }
    int k;
    cin >> k;
    vector<int> r;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        r.push_back(x);
    }
    FindCommon(v, z, r);
    return 0;
}