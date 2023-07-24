#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<vector<int>>& grid, vector<vector<int>> &dp, int i, int j)
    {
        if(i==0 && j==0)
            return grid[0][0];
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return INT_MAX;
        if(dp[i][j]!=-1) 
            return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(grid,dp,i-1,j),solve(grid,dp,i,j-1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
        return solve(grid,dp,grid.size()-1,grid[0].size()-1);
    }
};