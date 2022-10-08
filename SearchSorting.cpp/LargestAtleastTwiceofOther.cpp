#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int dominantIndex(vector<int> &nums)
{
    // sort(nums.begin(), nums.end());
    int ans = *max_element(nums.begin(), nums.end());
    int ansIndex = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (ans < nums[i] * 2 and nums[i] != ans)
            return -1;
        if (ans == nums[i])
            ansIndex = i;
    }
    return ansIndex;
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
    cout << dominantIndex(v);
    return 0;
}