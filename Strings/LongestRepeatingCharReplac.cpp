#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
You are given a string s and an integer k.
You can choose any character of the string and change it to
any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the
same letter you can get after performing the above operations.
*/
int characterReplacement(string s, int k)
{
    int n=s.length();
    vector<int> char_Counts(26);

    int window_start=0;
    int max_length=0;
    int max_count=0;
    for(int window_end=0;window_end<n;window_end++)
    {
        char_Counts[s[window_end]-'A']++;
        int current_Count=char_Counts[s[window_end]-'A'];
        max_count=max(max_count,current_Count);
        while(window_end-window_start-max_count+1>k)
        { char_Counts[s[window_start]-'A']--;
        window_start++;
            
        }
        max_length=max(max_length,window_end-window_start+1);
    }
     return max_length;
}
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout<<characterReplacement(s,k);
    return 0;
}