#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        int longest = 0;
        for (int i = 0; i < nums.size(); i++)
            s.insert(nums[i]);
        for (auto i : s)
        {
            if (s.find(i - 1) == s.end())
            {
                int curr = i;
                int seq = 1;
                while (s.find(i + 1) != s.end())
                {
                    curr = i + 1;
                    seq++;
                    i++;
                }
                longest = max(longest, seq);
            }
        }
        return longest;
    }
};