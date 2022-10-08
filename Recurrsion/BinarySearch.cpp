#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void PrintArray(int *arr, int s, int e)
{
    cout << "Elements in Array : -" << endl;
    for (int i = s; i < e; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool BinarySearch(int *arr, int n, int k, int s, int e)
{ // When we traverse whole array and didn`t find the element
    PrintArray(arr, s, e);
    if (s > e)
        return false;

    int mid = s + (e - s) / 2;
    cout << "Value of s = " << s << " Value of mid = " << mid << " Value of e = " << e << endl
         << endl;
    cout << "Element at arr[mid] = " << arr[mid] << endl;
    if (arr[mid] == k) // where element is present
        return true;
    else if (arr[mid] < k)
        return BinarySearch(arr, n, k, mid + 1, e);
    else
        return BinarySearch(arr, n, k, s, mid - 1);

}

int main()
{
    int n, k;
    cout << "Enter the size of array : -" << endl;
    cin >> n;
    cout << "Enter elements in Array :- " << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the element you want to search :- " << endl;
    cin >> k;
    int s = 0, e = n;
    if (BinarySearch(arr, n, k, s, e))
        cout << "Present" << endl;
    else
        cout << "Absent" << endl;
    return 0;
}