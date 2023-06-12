#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int ind, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans)
    {
        ans.push_back(temp);
        if(ind==nums.size())
        return;

        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,nums,temp,ans);
        return ans;
    }
};