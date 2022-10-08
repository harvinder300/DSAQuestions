#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void Generate(vector<vector<int>> &ans, vector<int> nums, int index)
{   // base case
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    
    for (int j = index; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);
        Generate(ans, nums, index + 1);
        //To get the original state of the string we have to re-swap
        swap(nums[index], nums[j]); // backtrack 
         
    }
}
vector<vector<int>> permute(vector<int> &nums)
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
    vector<vector<int>> ans = permute(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}