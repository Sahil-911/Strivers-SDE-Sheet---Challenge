#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int n, vector<int> &ans, int ind, int curr_sum)
{
    if (ind == n)
    {
        ans.push_back(curr_sum);
        return;
    }
    solve(arr, n, ans, ind + 1, curr_sum + arr[ind]);
    solve(arr, n, ans, ind + 1, curr_sum);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    solve(num, num.size(), ans, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
}