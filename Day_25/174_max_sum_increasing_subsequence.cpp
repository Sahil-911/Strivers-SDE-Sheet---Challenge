#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<vector<int>> dp;
    int solve(int prev, int idx, int arr[], int n)
    {
        if (idx == n)
            return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        if (prev == -1 || arr[idx] > arr[prev])
            return dp[idx][prev + 1] = max(arr[idx] + solve(idx, idx + 1, arr, n), solve(prev, idx + 1, arr, n));
        return dp[idx][prev + 1] = solve(prev, idx + 1, arr, n);
    }

    int maxSumIS(int arr[], int n)
    {
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return solve(-1, 0, arr, n);
    }
};