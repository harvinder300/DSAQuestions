#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int operation(string a, string b)
{
    int m = a.length(), n = b.length();

    // This parts checks whether conversion is possible or not
    if (n != m)
        return -1;
    int count[256];
    memset(count, 0, sizeof(count));
    // count characters in a
    for (int i = 0; i < n; i++)
        count[a[i]]++;

    for (int i = 0; i < n; i++)
        count[b[i]]--;

    for (int i = 0; i < 256; i++)
        if (count[i])
            return -1;

    int res = 0;
    for (int i = n - 1, j = n - 1; i >= 0;)
    {
        // If there is a mismatch, then keep incrementing
        // result 'res' until b[j] is not found in A[0..i]
        while (i >= 0 && a[i] != b[j])
        {
            i--;
            res++;
        }
        // If A[i] and B[j] match
        if (i >= 0)
        {
            i--;
            j--;
        }
    }
    return res;
} // aabbc
// aaabb
int main()
{
    string a, b;
    cin >> a >> b;
    cout << operation(a, b);
    return 0;
} /*
 int minOps(string& A, string& B)
 {
     int m = A.length(), n = B.length();

     // This parts checks whether conversion is possible or not
     if (n != m)
         return -1;
     int count[256];
     memset(count, 0, sizeof(count));
     // count characters in A
     for (int i = 0; i < n; i++)
         count[A[i]]++;

     for (int i = 0; i < n; i++)
         count[B[i]]--;

     for (int i = 0; i < 256; i++)
         if (count[i])
             return -1;

     int res = 0;
     for (int i = n - 1, j = n - 1; i >= 0;) {
         // If there is a mismatch, then keep incrementing
         // result 'res' until B[j] is not found in A[0..i]
         while (i >= 0 && A[i] != B[j]) {
             i--;
             res++;
         }
         // If A[i] and B[j] match
         if (i >= 0) {
             i--;
             j--;
         }
     }
     return res;
 }






 */