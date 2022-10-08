#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{ // -20 11 26 27 40
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;
    vector<vector<int>> ans;
    for (int i = 1; i < arr.size(); i++)
    {
        if (abs(arr[i] - arr[i - 1]) < minDiff)
            minDiff = abs(arr[i] - arr[i - 1]);
    }
    for (int i = 1; i < arr.size(); i++)
    {
        if (abs(arr[i] - arr[i - 1]) == minDiff)
            ans.push_back({arr[i-1], arr[i]});
    }
    return ans;
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
    vector<vector<int>> ans = minimumAbsDifference(v);
    for (int i = 0; i < ans.size(); i++)
    {
        vector<int> v1;
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}