#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:

    priority_queue<int> sm; //stores smaller half
    priority_queue<int,vector<int>,greater<int>> bg; //stores bigger half

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(sm.empty() || num<=sm.top())
            sm.push(num);
        else
            bg.push(num);
        
        if(sm.size()<bg.size())
        {
            sm.push(bg.top());
            bg.pop();
        }
        else if(sm.size()>bg.size()+1)
        {
            bg.push(sm.top());
            sm.pop();
        }

    }
    
    double findMedian() {
        if(sm.size()==bg.size())
        return (double) (bg.top()+sm.top())/2.0;
        else
        return (double) sm.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */