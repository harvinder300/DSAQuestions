#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that
 prod[i] is equal to the product of all the elements of arr[] except arr[i].
 Solve it without division operator in O(n) time.

*/

vector<int> productArray(vector<int> nums)
{
    int product = 1;
    vector<int> ans;
    // Traversing Left array and calculating the comullative product
    for (int i = 0; i < nums.size(); ++i)
    {
        product *= nums[i];
        ans.push_back(product);
    }
    // Traversing From Right To left of the array
    product = 1;
    for (int i = nums.size() - 1; i > 0; --i)
    {
        ans[i] = ans[i - 1] * product; // Replacing the actual product
        product = product * nums[i];
    }
    ans[0] = product; // Boundary case
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
    v = productArray(v);
    for (auto i : v)
        cout << i << " ";
    return 0;
}