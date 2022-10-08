#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int MergeArray(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    // Lengths of 2 arrays
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // 2 new Arrays
    int *first = new int[len1];
    int *second = new int[len2];

    // copying Values
    int MainArrayIndex = s;
    for (int i = 0; i < len1; i++)
        first[i] = arr[MainArrayIndex++];

    MainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
        second[i] = arr[MainArrayIndex++];

    // Merging 2 sorted arrays
    int index1 = 0, index2 = 0;
    MainArrayIndex = s;

    int InversionCount = 0;

    while (index1 < len1 and index2 < len2)
    {
        if (first[index1] < second[index2])
            arr[MainArrayIndex++] = first[index1++];
        else
        {
            arr[MainArrayIndex++] = second[index2++];
            // a[i]>a[j] and i<j
            InversionCount = InversionCount + (len1 - index1);
        }
    }
    // For remaining elements
    while (index1 < len1)
        arr[MainArrayIndex++] = first[index1++];
    while (index2 < len2)
        arr[MainArrayIndex++] = second[index2++];

    // Free the memory which is dynamically allocated
    delete[] first;
    delete[] second;
    return InversionCount;
}
int MergerSort(int *arr, int s, int e)
{
    if (s >=e)
        return 0;
    int mid = (s + e) / 2;

    int InversionCount = 0;
    InversionCount += MergerSort(arr, s, mid); // Counting Left Inversion

    InversionCount += MergerSort(arr, mid + 1, e); // Counting Right Inversion
    // Merging Arrays
    InversionCount = MergeArray(arr, s, e) + InversionCount;
    return InversionCount;
}
int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Inversion = " << MergerSort(v, 0, n - 1) << endl;
    /*for (int i = 0; i < n; i++)
        cout << v[i] << " ";*/
    return 0;
}