#include <bits/stdc++.h>
using namespace std;

class Queue
{
    queue<int> q;
    vector<int> que;

    bool Empty()
    {
        return que.size() == 0;
    }

    void push(int val)
    {
        que.push_back(val);
    }

    void pop()
    {
        if (!que.empty())
            que.erase(que.begin());
    }

    int Size()
    {
        return que.size();
    }

    int top()
    {
        if (!que.empty())
            return que[0];
        return -1;
    }
};