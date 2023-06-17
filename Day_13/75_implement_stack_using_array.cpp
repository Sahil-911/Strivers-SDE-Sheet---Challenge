#include <bits/stdc++.h>
using namespace std;

class Stack
{

    vector<int> st;

    bool empty()
    {
        return st.size()==0;
    }

    void push(int val)
    {
        st.push_back(val);
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st[st.size() - 1];
    }

    int size()
    {
        return st.size();
    }
};