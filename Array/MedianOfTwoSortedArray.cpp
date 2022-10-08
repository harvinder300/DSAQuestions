#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> mergeArray(vector<int> &a, vector<int> &b)
{
    vector<int> MergedArray;
    int index1 = 0, index2 = 0;
    while (index1 < a.size() and index2 < b.size())
    {
        if (a[index1] < b[index2])
            MergedArray.push_back(a[index1++]);
        else
            MergedArray.push_back(b[index2++]);
    }
    // For remaining elements
    while (index1 < a.size())
        MergedArray.push_back(a[index1++]);
    while (index2 < b.size())
        MergedArray.push_back(b[index2++]);
    return MergedArray;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> MergedArray = mergeArray(nums1, nums2);
    int n = MergedArray.size();
    int mid = 0 + (n - 0) / 2;
    double ans = 0;
    if (n % 2 == 0)
    {
        double x = MergedArray[mid] + MergedArray[mid - 1];
        ans = double(x) / 2;
    }
    else
        ans = MergedArray[mid];

    return ans;
}
int main()
{
    int n;
    cout << "Enter the size of 1st array :- " << endl;
    cin >> n;
    int x;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    vector<int> z;
    int m;
    cout << "Enter the size of 2nd array :- " << endl;
    cin >> m;
   
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        z.push_back(x);
    }
    double ans = findMedianSortedArrays(v, z);
    cout << ans;
    return 0;
}