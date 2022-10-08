#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;
    // cout << "checking for mid "<< mid <<endl;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
            pageSum += arr[i];
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
                return false;
            pageSum = arr[i];
        }
        if (studentCount > m)
            return false;
        // cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

int allocateBooks(int A[], int N, int M)
{
    int s = 0;
    int sum = 0;

    for (int i = 0; i < N; i++)
        sum += A[i];

    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;
    if (M > N) // For handling if No of students greater than the size of array
        return ans;

    while (s <= e)
    {
        if (isPossible(A, N, M, mid))
        {
            // cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
        mid = s + (e - s) / 2;
    }
    return ans;
}
int Allocate(int A[], int N, int M, int sum, int s, int e)
{
    if (s > e)
        return -1;
    
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
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i];
    int m, s = 0, e = sum;
    cin >> m;
    cout << Allocate(v, n, m, sum, s, e);
    return 0;
}