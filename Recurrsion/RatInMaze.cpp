#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isSafe(vector<vector<int>> &m, vector<vector<int>> visited, int x, int y, int n)
{
    if ((x >= 0 and x < n) and (y >= 0 and y < n) and visited[x][y] == 0 and m[x][y] == 1)
        return true;
    else
        return false;
}
void solve(vector<vector<int>> &m, vector<string> &ans, vector<vector<int>> visited, int x, int y, string path, int n)
{ // Base Case
    if (x == n - 1 and y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // every time we visited the block marking it '1'
    visited[x][y] = 1;
    // 4 choices D,L,R,U
    int newX, newY;
    
    // DOWN
    newX=x+1,newY=y;
    if (isSafe(m, visited, newX, newY, n))
    {
        path.push_back('D');
        solve(m, ans, visited, newX, newY, path, n);
        path.pop_back();
    }

    // left
    newX = x, newY = y - 1;
    if (isSafe(m, visited, newX, newY, n))
    {
        path.push_back('L');
        solve(m, ans, visited, newX, newY, path, n);
        path.pop_back();
    }

    // Right
    newX = x, newY = y + 1;
    if (isSafe(m, visited, newX, newY, n))
    {
        path.push_back('R');
        solve(m, ans, visited, newX, newY, path, n);
        path.pop_back();
    }

    // UP
    newX = x - 1, newY = y;
    if (isSafe(m, visited, newX, newY, n))
    {
        path.push_back('U');
        solve(m, ans, visited, newX, newY, path, n);
        path.pop_back();
    }
    // Backtracking the visited array for another path
    // So marking it non visited by '0'
    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    string path = "";

    if (m[0][0] == 0)
        return ans;
    vector<vector<int>> visited = m;

    // Marking every block non-visited
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;
    }
    // Source Index
    int srcx = 0;
    int srcy = 0;

    solve(m, ans, visited, srcx, srcy, path, n);
}
int main()
{
    int n, m, x;
    cout << "Enter the row size :-";
    cin >> n;
    cout << "Enter the column size :-";
    cin >> m;
    vector<vector<int>> vec;

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
    vector<string> ans = findPath(vec, n);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}