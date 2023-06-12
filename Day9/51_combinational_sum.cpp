#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int ind, int curr_sum, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (curr_sum > target)
            return;

        if (curr_sum == target)
        {
            ans.push_back(temp);
            return;
        }

        if (ind < candidates.size())
        {
            temp.push_back(candidates[ind]);
            solve(ind, curr_sum + candidates[ind], candidates, target, ans, temp);
            temp.pop_back();
            solve(ind + 1, curr_sum, candidates, target, ans, temp);
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, 0, candidates, target, ans, temp);
        return ans;
    }
};