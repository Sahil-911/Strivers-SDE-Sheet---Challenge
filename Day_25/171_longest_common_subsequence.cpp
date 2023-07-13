#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int solve(int i, int j, string text1, string text2)
    // {
    //     if(i<0 || j<0)
    //     return 0;

    //     if(text1[i]==text2[j])
    //     return 1+solve(i-1,j-1,text1,text2);
    //     return max(solve(i-1,j,text1,text2),solve(i,j-1,text1,text2));
    // }

    int longestCommonSubsequence(string text1, string text2)
    {
        // return solve(text1.length()-1,text2.length()-1,text1,text2);
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        for (int i = 1; i <= text1.size(); i++)
        {
            for (int j = 1; j <= text2.size(); j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.length()][text2.length()];
    }
};