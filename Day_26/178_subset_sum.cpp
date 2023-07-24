#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> dp;
    bool solve(int i, vector<int> &nums, int target)
    {
        if(target==0)
            return true;

        if(target<0 || i<0)
            return false;

        if(dp[i][target]!=-1)
            return dp[i][target]==0 ? false:true;

        bool res = solve(i-1,nums,target-nums[i]) || solve(i-1,nums,target);
        dp[i][target] = res==true ? 1:0;
        return res;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)
            return false;
        dp.resize(nums.size(),vector<int>(sum/2+1,-1));
        return solve(nums.size()-1,nums,sum/2);
    }
};