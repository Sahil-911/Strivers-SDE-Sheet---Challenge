#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.length() == 0)
            return true;
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.length(); i++)
        {
            if (!st.empty() || (s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{'))
                st.pop();
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};