#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // vector<vector<int>> dp;
    // int solve(int idx, int w, int wt[], int val[], int n)
    // {
    //     if(idx==n || w==0)
    //         return 0;

    //     if(dp[idx][w]!=-1)
    //         return dp[idx][w];

    //     if(wt[idx]<=w)
    //         return dp[idx][w]=max(val[idx]+solve(idx+1,w-wt[idx],wt,val,n),solve(idx+1,w,wt,val,n));
    //     return dp[idx][w]=solve(idx+1,w,wt,val,n);
    // }

    int knapSack(int w, int wt[], int val[], int n)
    {
        // dp.resize(n+1,vector<int>(w+1,-1));
        // return solve(0,w,wt,val,n);
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j <= w; j++)
            {
                if (wt[i] <= j)
                    dp[i][j] = max(val[i] + dp[i + 1][j - wt[i]], dp[i + 1][j]);
                else
                    dp[i][j] = dp[i + 1][j];
            }
        }
        return dp[0][w];
    }
};