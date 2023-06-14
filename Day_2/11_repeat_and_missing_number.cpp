#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int, int> ans;
    unordered_map<int, int> cnt;

    for (int i = 0; i < n; i++)
    {
        if (cnt.find(arr[i]) == cnt.end())
            cnt[arr[i]] = 1;
        else
            cnt[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (cnt.find(i) == cnt.end())
            ans.first = i;
        else if (cnt[i] == 2)
            ans.second = i;
    }

    return ans;
}
