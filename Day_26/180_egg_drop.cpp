#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve (int eggs, int floors, vector<vector<int>> &dp)
    {
        if (eggs == 1 || floors <= 1)
            return floors;

        if (dp[eggs][floors] != -1)
            return dp[eggs][floors];

        int ans = INT_MAX;

        for (int k = 1; k <= floors; k++)
        {
            int dead = solve (eggs - 1, k - 1, dp);
            int alive = solve (eggs, floors - k, dp);
            int steps = 1 + max(dead, alive);
            
            ans = min(ans, steps);
        }

        return dp[eggs][floors] = ans;
    }
    
    int eggDrop(int k, int n) 
    {
        vector<vector<int>> dp (k + 1, vector<int> (n + 1, -1));
        return solve (k, n, dp);
    }
};