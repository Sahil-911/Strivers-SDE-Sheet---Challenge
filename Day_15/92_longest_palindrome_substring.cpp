#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int mx = 0, ind = -1;
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(s.length() + 1, false));
        for (int g = 0; g < s.length(); g++)
        {
            for (int i = 0, j = i + g; j < s.length(); i++, j++)
            {
                if (g == 0)
                    dp[i][j] = true;
                else if (g == 1 && s[i] == s[j])
                    dp[i][j] = true;
                else if (dp[i + 1][j - 1] && s[i] == s[j])
                    dp[i][j] = true;
                else
                    dp[i][j] = 0;

                if (dp[i][j])
                {
                    mx = g + 1;
                    ind = i;
                }
            }
        }
        return s.substr(ind, mx);
    }
};