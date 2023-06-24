#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int mx=0;
//         for(int i=0;i<n;i++)
//         {
//             int minHeight=INT_MAX;
//             for(int j=i;j<n;j++)
//             {
//                 minHeight= min(minHeight, heights[j]);
//                 mx = max(mx, minHeight*(j-i+1));
//             }
//         }
//         return mx;
//     }
// };

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         stack<int> st;
//         vector<int> leftsmall(heights.size()), rightsmall(heights.size());

//         //finding left small for all elements
//         for(int i=0;i<heights.size();i++)
//         {
//             while(!st.empty() && heights[st.top()]>=heights[i])
//                 st.pop();
            
//             if(!st.empty())
//                 leftsmall[i] = st.top()+1;
//             else
//                 leftsmall[i] = 0;

//             st.push(i);
//         }

//         while(!st.empty())
//             st.pop();

//         //finding right small for all elements
//         for(int i=heights.size()-1;i>=0;i--)
//         {
//             while(!st.empty() && heights[st.top()]>=heights[i])
//                 st.pop();

//             if(!st.empty())
//                 rightsmall[i] = st.top()-1;
//             else
//                 rightsmall[i] = heights.size()-1;

//             st.push(i);
//         }

//         int mx = INT_MIN;
//         for(int i=0;i<heights.size();i++)
//             mx = max(mx,(rightsmall[i]-leftsmall[i]+1)*heights[i]);
//         return mx;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA=0;
        for(int i=0;i<=heights.size();i++)
        {
            while(!st.empty() && (i==heights.size() || heights[st.top()]>=heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, height*width);
            }
            st.push(i);
        }
        return maxA;
    }
};