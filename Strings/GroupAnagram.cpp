#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    unordered_map<string,int> m;
    int idx=0;
    for (int i = 0; i < strs.size(); i++)
    {
        string s=strs[i];
       sort(s.begin(),s.end());
       if(m.find(s)==m.end())
       {
         m[s]=idx++;
         ans.push_back({strs[i]});
       }
       else
        ans[m[s]].push_back(strs[i]);
                
    }
    return ans;
}
int main()
{

    vector<string> s;

    string x;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.push_back(x);
    }
    vector<vector<string>> ans = groupAnagrams(s);

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