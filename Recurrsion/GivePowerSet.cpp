#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Question Name :- 78. Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example:-

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

*/
void GenerateSubset(vector<int> nums, vector<int> output, vector<vector<int>> &ans, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // Excluding ELement
    GenerateSubset(nums, output, ans, index + 1);
    // Including Element
    int ele = nums[index];
    output.push_back(ele);
    GenerateSubset(nums, output, ans, index + 1);
}
vector<vector<int>> PowerSet(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    
    int index = 0;
    GenerateSubset(nums, output, ans, index);
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
    vector<vector<int>> ans;
    ans = PowerSet(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}