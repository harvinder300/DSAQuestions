#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void PrintZigZag(vector<vector<int>> A, int n)
{
    vector<int> ans(n * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i + j] = A[j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int n, m;
    cout << "Enter the row size : -" << endl;
    cin >> n;
    cout << "Enter the coulumn size" << endl;
    cin >> m;
    vector<vector<int>> vec;
    int x;
    for (int i = 0; i < n; i++)
    {
        vector<int> v1;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            v1.push_back(x);
        }
        vec.push_back(v1);
    }
    PrintZigZag(vec, n);
    return 0;
}