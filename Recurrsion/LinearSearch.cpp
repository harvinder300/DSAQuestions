#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void PrintArray(int *arr, int n)
{
    cout << "Size of Array " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
bool LinearSearch(int *arr, int n, int k)
{   PrintArray(arr,n);
    if (n == 0)
        return false;
    if (arr[0] == k)
        return true;
    else
    {
        bool remaining = LinearSearch(arr + 1, n - 1, k);
        return remaining;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    if (LinearSearch(arr, n, k))
        cout << "Present" << endl;
    else
        cout << "Absent" << endl;
    return 0;
}