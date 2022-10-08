#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int ans = 1, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ans)
            ans++;
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

    cout << firstMissingPositive(v);
    return 0;
}