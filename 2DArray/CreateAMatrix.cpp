#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Create a matrix with alternating rectangles of O and X

Write a code which inputs two numbers m and n and creates a matrix of size m x n (m rows and n columns) in which every
elements is either X or 0. The Xs and 0s must be filled
alternatively, the matrix should have outermost rectangle of Xs, then a rectangle of 0s,
then a rectangle of Xs, and so on.
*/
vector<vector<char>> generateMatrix(int n, int m)
{ // n =no of rows
    // m = no of col
    vector<vector<char>> ans_Matrix(n, vector<char>(m, 0));
    int top = 0, bottom = n - 1, right = m - 1, left = 0;
    char x = 'X';
    while (top <= bottom and left <= right)
    { // TOP ROW
        for (int i = left; i <= right; i++)
            ans_Matrix[top][i] = x;
        top++;

        // RIGHT COULUMN
        for (int i = top; i <= bottom; i++)
            ans_Matrix[i][right] = x;
        right--;


        // BOTTOM ROW(reverse)
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans_Matrix[bottom][i] = x;
            
            bottom--;
        }
       
        // LEFT COULUMN(reverse)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans_Matrix[i][left] = x;

            left++;
        }
        x = (x == '0') ? 'X' : '0';
    }

    return ans_Matrix;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> ans = generateMatrix(n, m);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}