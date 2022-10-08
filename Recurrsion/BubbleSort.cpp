#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void BubbleSort(int *arr, int n)
{
    if (n == 0 or n == 1)
        return;
    // Solving only 1 case
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    // Other cases recursion will handle
    BubbleSort(arr, n - 1);
}
int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout<<"After Sorting "<<endl;
    BubbleSort(v, n);
    for (int i = 0; i < n; i++)
        cout << v[i]<<" ";

    return 0;
}