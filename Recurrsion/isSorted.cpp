#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isSorted(int *arr, int n)
{
    if (n == 0 or n == 1)
        return true;
    if (arr[0] > arr[1])
        return false;
    else
    {
        bool remainingPart = isSorted(arr + 1, n - 1);
        return remainingPart;
    }
}
int main()
{
    int n = 5;
    int arr[5];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (isSorted(arr, n))
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Unsorted" << endl;
    }
    return 0;
}