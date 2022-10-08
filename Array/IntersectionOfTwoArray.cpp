#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void FindAns(vector<int> &nums, vector<int> &ans, unordered_map<int, int> &mp)
{

    for (auto i : nums)
    {
        if (mp.find(i) != mp.end() and mp[i] > 0)
        {

            ans.push_back(i);
            mp[i]--;
        }
    }
}
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    vector<int> ans;
    if (nums1.size() >= nums2.size())
    {
        for (auto i : nums1)
            mp[i]++;
        FindAns(nums2, ans, mp);
    }
    else
    {
        for (auto i : nums2)
            mp[i]++;
         FindAns(nums1, ans, mp);
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
    int m;
    cin >> m;
    vector<int> z;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        z.push_back(x);
    }
    vector<int> ans = intersect(v, z);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}