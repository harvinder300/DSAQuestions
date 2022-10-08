#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int Partition(int *arr, int s, int e)
{
    int Pivot = arr[s];
    int Count = 0;
    // Counting no of elements smaller than PIVOT
    for (int i = s + 1; i <= e; i++)
        if (arr[i] <= Pivot)
            Count++;
   
    int PivotIndex = s + Count; // Pivot Right place

    swap(arr[PivotIndex], arr[s]); // Swapping

    int i = s, j = e;

    while (i < PivotIndex and j > PivotIndex)
    {
        while (arr[i] <= Pivot)
            i++;
        while (arr[j] > Pivot)
            j--;
        if (i < PivotIndex and j > PivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return PivotIndex;
}
void QuickSort(int *arr, int s, int e)
{
    if (s >= e)
        return;
    int p = Partition(arr, s, e);

    QuickSort(arr, s, p - 1); // Left Part
    QuickSort(arr, p + 1, e); // Right part
}
int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Before Sorting : -" << endl;
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;

    QuickSort(v, 0, n - 1);

    cout << "After Sorting : -" << endl;
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}