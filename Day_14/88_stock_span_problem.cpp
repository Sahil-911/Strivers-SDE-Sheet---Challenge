#include<bits/stdc++.h>
using namespace std;

// class StockSpanner {
// public:

//     stack<int> st;
//     StockSpanner() {
//     }
    
//     int next(int price) {
//         stack<int> tt;
//         int cnt = 1;
//         while(!st.empty() && st.top()<=price)
//         {
//             cnt++;
//             tt.push(st.top());
//             st.pop();
//         }
//         while(!tt.empty())
//         {
//             st.push(tt.top());
//             tt.pop();
//         }
//         st.push(price);
//         return cnt;
//     }
// };

// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */

class StockSpanner {
public:

    stack<pair<int,int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
        if(st.empty())
        {
            st.push({price,1});
            return 1;
        }
        else
        {
            if(st.top().first>price)
                st.push({price,1});
            else
            {
                int cnt = 1;
                while(!st.empty() && st.top().first<=price)
                {
                    cnt += st.top().second;
                    st.pop();
                }
                st.push({price,cnt});
            }
            return st.top().second;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */