#include <bits/stdc++.h>
using namespace std;

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    vector<pair<int, int>> pairs;
    int n = start.size();
    for (int i = 0; i < n; i++)
        pairs.push_back({finish[i], start[i]});

    sort(pairs.begin(), pairs.end());

    int prev = pairs[0].first;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (prev <= pairs[i].second)
        {
            cnt++;
            prev = pairs[i].first;
        }
    }
    return cnt;
}