#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int thirdMax(vector<int> &nums)
{
   sort(nums.begin(),nums.end(),greater<int>());
   nums.erase(unique(nums.begin(),nums.end()),nums.end());
   if(nums.size()<3)
     return nums[0];
    return nums[2];
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
    cout<<thirdMax(v);
    return 0;
}