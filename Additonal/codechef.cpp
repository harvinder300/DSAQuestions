#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int numberOfHolidays = 8;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 7 == 0 || (arr[i] + 1) % 7 == 0)
            {}
            else
                numberOfHolidays++;
        }
        cout << numberOfHolidays << endl;
    }
    return 0;
}
/*

int main() {
   int a;
   cin>>a;
   for(int i=0;i<a;i++)
   {
       int b,sum=8;
       cin>>b;
       for(int i=0;i<b;i++)
       {
           int c,d;
           cin>>c;
           if(!c%7==0 || c!=6 || c!=13 || c!=20 || c!=27)
           {
               sum++;
           }

       }

      cout<<sum<<endl;
   }
    return 0;
}
*/