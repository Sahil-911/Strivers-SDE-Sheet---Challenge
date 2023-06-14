#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int unique(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j])
            return dp[i][j];
        if (i == m - 1 && j == n - 1)
            return 1;
        return dp[i][j] = unique(i + 1, j, m, n, dp) + unique(i, j + 1, m, n, dp);
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        return unique(0, 0, m, n, dp);
    }
};