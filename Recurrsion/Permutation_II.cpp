#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void Generate(set<vector<int>> &ans, vector<int> nums, int index)
{
    if (index >= nums.size())
    {
        ans.insert(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);
        Generate(ans, nums, index + 1);
        swap(nums[index], nums[j]);
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    set<vector<int>> res;

    int index = 0;
    Generate(res, nums, index);
    vector<vector<int>> ans(res.begin(), res.end());
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
    vector<vector<int>> ans = permuteUnique(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}