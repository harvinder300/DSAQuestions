#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void Generate(vector<vector<int>> &ans, vector<int> nums, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
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
    vector<vector<int>> ans;
    int index = 0;
    Generate(ans, nums, index);
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
    vector<vector<int>> ans=permuteUnique(v);
    
    return 0;
}