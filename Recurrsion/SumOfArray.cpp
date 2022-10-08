#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int SumOfArray(int *arr, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    int remainingPart = SumOfArray(arr + 1, n - 1);
    int sum = arr[0] + remainingPart;
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Sum of the Array = " << SumOfArray(arr, n) << endl;
    return 0;
}