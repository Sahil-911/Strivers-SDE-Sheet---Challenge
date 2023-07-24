#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> dp;

    int solve(int i, vector<int>& coins, int amount)
    {
        if(amount==0)
            return 0;

        if(i==-1 || amount<0)
            return 1e5;

        if(dp[i][amount]!=-1)
            return dp[i][amount];

        return dp[i][amount] = min(1+solve(i,coins,amount-coins[i]),solve(i-1,coins,amount));
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(),vector<int> (amount+1,-1));
        int ans = solve(coins.size()-1,coins,amount);
        return ans>=1e5 ? -1:ans;
    }
};