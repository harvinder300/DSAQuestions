#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int longestValidParentheses(string s)
{
    stack<int> st;
    int count = 0;
    st.push(-1);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')')
        {
            st.pop();
            if (st.empty())
                st.push(i);
            else
                count = max(count, i - st.top());
        }
    }
    return count;
}
int main()
{
    string s;
    cin >> s;
    cout << longestValidParentheses(s);
    return 0;
}