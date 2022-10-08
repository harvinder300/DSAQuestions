#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
*/
bool checkIfExist(vector<int> &arr)
{ // arr= 2 3 5 10
  // duplicate= 4 6 10 20
    /*for(int i =0;i<arr.size();i++)
    {
        for(int j=0;j<arr.size();j++)
        {
            if(i!=j and arr[i]==2*arr[j])
            {
                return true;
            }
        }
    }
    return false;*/
    set<int> s(arr.begin(), arr.end());
    int count = 0;
    for (auto i : arr)
        if (i == 0)
            count++;
        else if (s.count(i * 2))
            return true;
    if (count > 1)
        return true;
    return false;
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
    cout << checkIfExist(v);
    return 0;
}