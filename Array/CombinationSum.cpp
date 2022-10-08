#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Explanation:

2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

*/
void Combo(vector<int> &candidates, vector<vector<int>> &ans, vector<int> &res, int target, int i)
{
    if (target == 0)
    {
        ans.push_back(res);
        return;
    }

    while (i < candidates.size() and target - candidates[i] >= 0)
    {
        res.push_back(candidates[i]);
        Combo(candidates, ans, res, target - candidates[i], i);
        ++i;
        res.pop_back();//backtracking
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> res;
    Combo(candidates, ans, res, target, 0);
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
    int target;
    cin >> target;
    vector<vector<int>> ans = combinationSum(v, target);
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