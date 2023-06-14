#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++)
            pairs.push_back({end[i], start[i]});

        sort(pairs.begin(), pairs.end());

        int cnt = 1;
        int prevEnd = pairs[0].first;
        for (int i = 1; i < n; i++)
        {
            if (pairs[i].second > prevEnd)
            {
                cnt++;
                prevEnd = pairs[i].first;
            }
        }

        return cnt;
    }
};

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<vector<int>> pairs;
    for (int i = 0; i < n; i++)
        pairs.push_back({end[i], start[i], i + 1});

    sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b)
         {
        if(a[0]==b[0])
            return a[2] <b[2];
        return a[0] < b[0]; });

    vector<int> ans;
    ans.push_back(pairs[0][2]);
    int prevEnd = pairs[0][0];
    for (int i = 1; i < n; i++)
    {
        if (pairs[i][1] > prevEnd)
        {
            ans.push_back(pairs[i][2]);
            prevEnd = pairs[i][0];
        }
    }

    return ans;
}