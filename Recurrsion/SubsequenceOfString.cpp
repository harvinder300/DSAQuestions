#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void Solve(string s, vector<string> &ans, int index, string output)
{
    // base case
    if (index >= s.length())
    {   //to not include empty string
        if (output.length() > 0)
            ans.push_back(output);
        return;
    }
    // exclude
    Solve(s, ans, index + 1, output);
   
    // Include
    char ele = s[index];
    output.push_back(ele);
    Solve(s, ans, index + 1, output);
}
vector<string> GiveSubsequence(string s)

{
    vector<string> ans;
    string output = "";
    int index = 0;
    Solve(s, ans, index, output);
    return ans;
}
int main()
{
    string s;
    cin >> s;
    vector<string> ans = GiveSubsequence(s);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}