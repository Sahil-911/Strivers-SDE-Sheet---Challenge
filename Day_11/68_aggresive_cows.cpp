#include <bits/stdc++.h>
using namespace std;

bool ifPossible(int mid, vector<int> &stalls, int k)
{
    int co = stalls[0], cnt = 1;
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - co >= mid)
        {
            cnt++;
            co = stalls[i];
        }
        if (cnt == k)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[stalls.size() - 1] - stalls[0];
    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (ifPossible(mid, stalls, k))
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}