#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &v)
    {
        sort(v.begin(), v.end());
        set<vector<int>> s;
        for (int i = 0; i < v.size() - 2; i++)
        {
            int j = i + 1;
            int k = v.size() - 1;
            while (j < k)
            {
                if (v[i] + v[j] + v[k] == 0)
                {
                    s.insert({v[i], v[j], v[k]});
                    j++;
                    k--;
                }
                else if (v[i] + v[j] + v[k] < 0)
                    j++;
                else
                    k--;
            }
        }
        vector<vector<int>> ans;
        for (auto i : s)
            ans.push_back(i);
        return ans;
    }
};