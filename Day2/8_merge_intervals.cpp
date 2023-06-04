#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (ans.size() == 0 || ans.back()[1] < intervals[i][0])
                ans.push_back(intervals[i]);
            else
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};