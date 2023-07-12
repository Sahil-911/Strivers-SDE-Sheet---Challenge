#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // int solve(int prev, int idx, vector<int> &nums)
    // {
    //     if(idx==nums.size())
    //     return 0;

    //     if(dp[idx][prev+1]!=-1)
    //     return dp[idx][prev+1];

    //     if(prev==-1 || nums[idx]>nums[prev])
    //         return dp[idx][prev+1] = max(1+solve(idx,idx+1,nums),solve(prev,idx+1,nums));
    //     return dp[idx][prev+1] = solve(prev,idx+1,nums);
    // }

    int lengthOfLIS(vector<int>& nums) {
        // dp.resize(nums.size(),vector<int>(nums.size()+1,-1));
        // return solve(-1,0,nums);
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,0));
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=i-1;j>=-1;j--)
            {
                if(j==-1 || nums[i]>nums[j])
                    dp[i+1][j+1] = max(1+dp[i+1][i+1],dp[i+1][j+1]);
                dp[i][j+1] = dp[i+1][j+1];
            }
        }
        return dp[0][-1+1];
    }
};