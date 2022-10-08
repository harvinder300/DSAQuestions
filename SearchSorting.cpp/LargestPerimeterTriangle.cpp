#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int largestPerimeter(vector<int> &nums)
{  //3 2 3 4
// 2 3 3 4
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 3; i >= 0; i--)
        if (nums[i] + nums[i + 1] > nums[i + 2])
            return nums[i] + nums[i + 1] + nums[i + 2];

    return 0;
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
    cout << largestPerimeter(v);
    return 0;
}