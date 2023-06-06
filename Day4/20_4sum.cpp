#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &v, int a)
    {
        sort(v.begin(), v.end());
        int n = v.size();
        set<vector<int>> s;

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && v[i] == v[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && v[j] == v[j - 1])
                    continue;

                long long target = (long long)a - ((long long)v[i] + (long long)v[j]);
                int l = j + 1, r = n - 1;

                while (l < r)
                {
                    if (v[l] + v[r] == target)
                    {
                        s.insert({v[i], v[j], v[l], v[r]});
                        l++;
                        r--;
                    }
                    else if (v[l] + v[r] < target)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for (auto i : s)
            ans.push_back(i);

        return ans;
    }
};
