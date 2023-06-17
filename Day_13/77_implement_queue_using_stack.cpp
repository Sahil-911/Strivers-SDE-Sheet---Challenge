#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> st, tt;

    MyQueue()
    {
    }

    void push(int x)
    {
        st.push(x);
    }

    int pop()
    {
        if (st.empty())
            return 0;
        while (st.size() != 1)
        {
            tt.push(st.top());
            st.pop();
        }
        int poped = st.top();
        st.pop();
        while (!tt.empty())
        {
            st.push(tt.top());
            tt.pop();
        }
        return poped;
    }

    int peek()
    {
        if (st.empty())
            return 0;
        while (st.size() != 1)
        {
            tt.push(st.top());
            st.pop();
        }
        int p = st.top();
        while (!tt.empty())
        {
            st.push(tt.top());
            tt.pop();
        }
        return p;
    }

    bool empty()
    {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */