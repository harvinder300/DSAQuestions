#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Find a common element in all rows of a given row-wise sorted matrix

Given a matrix where every row is sorted in increasing order.
Write a function that finds and returns a common element in all rows.
If there is no common element, then returns -1.

Input: mat[4][5] = { {1, 2, 3, 4, 5},
                    {2, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9},
                  };
Output: 5
*/
int FindCommon(vector<vector<int>> v)
{
    unordered_map<int, int> m;
    int ans = -1;
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i][0]]++;
        for (int j = 1; j < v[0].size(); j++)
        {
            if (v[i][j] != v[i][j - 1])
                m[v[i][j]]++;
        }
    }
    for (auto i : m)
    {
        if (i.second == v.size())
            return i.first;
    }
    return -1;
}
int main()
{
    int n, m;
    cout << "Enter the row size :-";
    cin >> n;
    cout << "Enter the column size :-";
    cin >> m;
    vector<vector<int>> vec;
    int x;
    for (int i = 0; i < n; i++)
    {
        vector<int> v1;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            v1.push_back(x);
        }
        vec.push_back(v1);
    }
    cout<<FindCommon(vec);
    return 0;
}