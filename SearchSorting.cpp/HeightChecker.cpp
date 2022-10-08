#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int heightChecker(vector<int> &heights)
{
    vector<int> expected = heights;
    sort(expected.begin(), expected.end());
    int count = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        if (expected[i] != heights[i])
            count++;
    }
    return count;
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
    cout<<heightChecker(v);
    return 0;
}