#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &v)
    {
        int maxi = 0, sum = 0;
        unordered_map<int, int> um;
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];
            if (sum == 0)
                maxi = i + 1;
            else
            {
                if (um.find(sum) != um.end())
                    maxi = max(maxi, i - um[sum]);
                else
                    um[sum] = i;
            }
        }
        return maxi;
    }
};