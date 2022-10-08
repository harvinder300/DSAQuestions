#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{

    unordered_map<int, int> s;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];
        if (s.find(target - nums[i]) != s.end() and s.find(diff)->second != i)
        {
            int x = s.find(diff)->second;
            res.push_back(i);
            res.push_back(x);
            return res;
        }
        s[nums[i]] = i;
    }
    return res;
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
    int target;
    cin >> target;
    vector<int> ans = twoSum(v, target);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}