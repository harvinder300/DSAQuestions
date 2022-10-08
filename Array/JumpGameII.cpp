#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int jump(vector<int> &nums)
{   int numberOfJumps=0;
   for(int i=1;i<nums.size();i++)
   {
        if(nums[i-1]<nums[i])
        {
            
        }
   }   
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
    cout<<jump(v);
    return 0;
}