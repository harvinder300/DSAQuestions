#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*

Let us consider below problem as an example.
Given two numbers say a and b, mark the multiples
of 2 and 5 between a and b using less than O(|b – a|) space and output each of the multiples.

Note : We have to mark the multiples i.e save (key, value) pairs in memory such that each key
either have value as 1 or 0 representing as multiple of 2 or 5 or not respectively.

*/
void SpaceOptimization(int a, int b)
{
    int size = abs(b - a)+1;
    vector<int> ans(size);

    for (int i = a; i <= b; i++)
    {
        if (i % a == 0 or i % b == 0)
            ans[i - a] = 1;
    }

    for (int i = a; i <= b; i++)
    {
        if (ans[i - a] == 1)
            cout << i << " ";
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    SpaceOptimization(a, b);
    return 0;
}