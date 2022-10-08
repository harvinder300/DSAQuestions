#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid)
{
    int CowsCount = 1;
    int LastPos = arr[0];
    // cout << "checking for mid "<< mid <<endl;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - LastPos >= mid)
        {
            CowsCount++;
            if (CowsCount == m)
                return true;
            LastPos = arr[i];
        }
    }
    return false;
}

int Agrresive_Cows(int A[], int N, int M)
{
    sort(A, A + N);
    int s = 0,max = A[N - 1],e = max;
    int ans = -1;
    int mid = s + (e - s) / 2;
    if (M > N)
        return ans;
    while (s <= e)
    {
        if (isPossible(A, N, M, mid))
        {
        
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int m;
    cin >> m;
    cout << Agrresive_Cows(v, n, m);
    return 0;
}