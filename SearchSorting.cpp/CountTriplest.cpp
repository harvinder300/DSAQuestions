#include <bits/stdc++.h>
#include <iostream>
using namespace std; // 1 3 4 5 7
int countTriplets(vector<int> v, int sum)
{
    sort(v.begin(), v.end());
    int n = v.size();
    int ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;

        while (j < k)
        {
            if (v[i] + v[j] + v[k] >= sum)
                k--;
            else
            {
                ans += (k - j);
                j++;
            }
        }
    }
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
    int sum;
    cin >> sum;

    cout << countTriplets(v, sum);
    return 0;
}