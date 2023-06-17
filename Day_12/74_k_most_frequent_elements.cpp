#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++)
        {
            um[nums[i]]++;
        }
        vector<pair<int, int>> ans;
        for (auto i : um)
        {
            ans.push_back({i.first, i.second});
        }
        sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.second > b.second; });
        vector<int> out;
        for (int i = 0; i < k; i++)
            out.push_back(ans[i].first);
        return out;
    }
};

// class Solution
// {
// public:
//     vector<int> topKFrequent(vector<int> &nums, int k)
//     {
//         unordered_map<int, int> um;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             um[nums[i]]++;
//         }
//         auto bigger = [&](int a, int b)
//         {
//             return um[a] > um[b];
//         };
//         priority_queue<int, vector<int>, decltype(bigger)> pq(bigger);
//         for (auto &[key, v] : um)
//         {
//             pq.push(key);
//             if (pq.size() > k)
//                 pq.pop();
//         }
//         vector<int> ans(k);
//         copy(&(pq.top()), &(pq.top()) + k, &ans[0]);
//         return ans;
//     }
// };