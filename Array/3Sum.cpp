#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void TwoSumSorted(vector<int> &nums, int low, int high, int target, vector<vector<int>> &ans)
{
    int number = nums[low - 1];

    while (low < high)
    {
        if (nums[low] + nums[high] < target)
            low++;
        else if (nums[low] + nums[high] > target)
            high--;
        else
        {
            vector<int> res;
            res.push_back(number);
            res.push_back(nums[low]);
            res.push_back(nums[high]);

            // skipping  duplicates
            ans.push_back(res);

            while (low < high and nums[low] == nums[low + 1])
                low++;
            while (low < high and nums[high] == nums[high - 1])
                high--;
            low++;
            high--;
        }
    }
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
        if (i == 0 or nums[i - 1] != nums[i])
            TwoSumSorted(nums, i + 1, nums.size() - 1, -nums[i], ans);
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

    vector<vector<int>> ans = threeSum(v);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}