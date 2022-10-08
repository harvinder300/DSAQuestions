#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/*
Given two strings wild and pattern where wild string may contain wild card characters and pattern string is a normal string.
 Determine if the two strings match. The following are the allowed wild card characters in first string :-

* --> This character in string wild can be replaced by any sequence of characters, 
it can also be replaced by an empty string.
? --> This character in string wild can be replaced by any one character.

DP ka hai ye

*/

bool wildCardMatch(string wild,string pattern)
{
    string ans="";
     int wild_size=wild.size();;
     int pattern_size=pattern.size();
    for(int i =0,j=0;i<wild_size;i++)
    {
        if(wild[i]!=pattern[j])
        {
            for(int k =i;k<pattern_size;k++ )
            {
              ans=ans+pattern[k];
              if(ans[i]==pattern[k])
                break;
            }
        }
        ans=ans+wild[i];
        j++;
    }

}
int main(){
    string wild,pattern;
    cin>>wild>>pattern;

    return 0;
}