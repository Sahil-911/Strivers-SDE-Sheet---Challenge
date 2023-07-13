#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // vector<vector<int>> dp;

    // int solve(string &w1, string &w2, int i, int j)
    // {
    //     if(i<0 || j<0)
    //         return i+j+2;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     if(w1[i] == w2[j])
    //         return dp[i][j] = solve(w1,w2,i-1,j-1);
    //     return dp[i][j] = min(1+solve(w1,w2,i-1,j-1),min(1+solve(w1,w2,i-1,j),1+solve(w1,w2,i,j-1)));
    // }

    int minDistance(string w1, string w2)
    {
        // dp.resize(w1.length(),vector<int> (w2.length(),-1));
        // return solve(w1,w2,w1.length()-1,w2.length()-1);
        vector<vector<int>> dp(w1.length() + 1, vector<int>(w2.length() + 1, 0));
        for (int i = 0; i <= w1.length(); i++)
            dp[i][0] = i;
        for (int j = 0; j <= w2.length(); j++)
            dp[0][j] = j;
        for (int i = 1; i <= w1.length(); i++)
        {
            for (int j = 1; j <= w2.length(); j++)
            {
                if (w1[i - 1] == w2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(1 + dp[i - 1][j], min(1 + dp[i - 1][j - 1], 1 + dp[i][j - 1]));
            }
        }
        return dp[w1.length()][w2.length()];
    }
};