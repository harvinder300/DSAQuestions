#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 6
#define M 6
// Application of Flood Fill ALgo
void FloodFillUpdate(char screen[][N], int x, int y, char prevC, char newC)
{

    if (x < 0 or x >= M or y < 0 or y >= N)
        return;
    if (screen[x][y] != prevC)
        return;
    screen[x][y] = newC;

    FloodFillUpdate(screen, x + 1, y, prevC, newC);
    FloodFillUpdate(screen, x - 1, y, prevC, newC);
    FloodFillUpdate(screen, x, y + 1, prevC, newC);
    FloodFillUpdate(screen, x, y - 1, prevC, newC);
}
int replaceSurrounded(char mat[][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] == '0')
                mat[i][j] = '-';
        }
    }

    for (int i = 0; i < M; i++) // left side
        if (mat[i][0] == '-')
            FloodFillUpdate(mat, i, 0, '-', '0');
    for (int i = 0; i < M; i++) // Right Side
        if (mat[i][N - 1] == '-')
            FloodFillUpdate(mat, i, N - 1, '-', '0');
    for (int i = 0; i < N; i++) // Top side
        if (mat[0][i] == '-')
            FloodFillUpdate(mat, 0, i, '-', 'O');
    for (int i = 0; i < N; i++) // Bottom side
        if (mat[M - 1][i] == '-')
            FloodFillUpdate(mat, M - 1, i, '-', 'O');
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] == '-')
                mat[i][j] = 'X';
        }
    }
    
}
int main()
{
    char mat[][N] = {
        {'X', 'O', 'X', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'X'},
        {'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'O'},
    };
    
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}