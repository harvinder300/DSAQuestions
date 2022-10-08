#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int arrayPairSum(vector<int> &nums)
{ // 1 2 3 4
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < nums.size(); i += 2)
        ans += min(nums[i], nums[i + 1]);
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
    cout << arrayPairSum(v);
    return 0;
}