#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void Generate(string digits, vector<string> &ans, int index, string output, string map[])
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string val = map[number];

    for (int i = 0; i < val.length(); i++)
    {
        output.push_back(val[i]);
        Generate(digits, ans, index+1, output, map);
        output.pop_back();//Backtracking  ka part hai ye 
    }
}
vector<string> letterCombination(string digits)
{
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        string output;
        int index = 0;
        string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        Generate(digits, ans, index, output, map);
        return ans;
}
int main()
{
    string s;
    cin >> s;
    vector<string> ans = letterCombination(s);
    cout<<"Letter Combinations are : - ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}