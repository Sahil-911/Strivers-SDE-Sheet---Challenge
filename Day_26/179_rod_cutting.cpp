#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, int> dp;

    int dfs(int i, int j, vector<int> &cuts)
    {
        if (j - i == 1)
            return 0;

        string temp = to_string(i) + "s" + to_string(j);
        if (dp.find(temp) != dp.end())
            return dp[temp];

        int mini = INT_MAX;

        for (auto &c : cuts)
            if (i < c && c < j)
                mini = min(mini, j - i + dfs(i, c, cuts) + dfs(c, j, cuts));

        return dp[temp] = mini == INT_MAX ? 0 : mini;
    }

    int minCost(int n, vector<int> &cuts)
    {
        if (!n)
            return 0;
        return dfs(0, n, cuts);
    }
};