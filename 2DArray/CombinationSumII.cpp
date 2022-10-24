#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void solve(int index, int target, vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index and candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        temp.push_back(candidates[i]);
        solve(i + 1, target - candidates[i], candidates, temp, ans);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, target, candidates, temp, ans );
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
    vector<vector<int>> ans = combinationSum2(v, target);
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