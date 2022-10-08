#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else
        {
            if (st.empty())
                return false;
            if (c == ']' and st.top() != '[')
                return false;
            if (c == '}' and st.top() != '{')
                return false;
            if (c == ')' and st.top() != '(')
                return false;
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    string s;
    cin >> s;
    cout << isValid(s);
    return 0;
}