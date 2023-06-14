#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int el = -1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                el = nums[i];
                cnt = 1;
            }
            else if (el == nums[i])
                cnt++;
            else
                cnt--;
        }
        cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == el)
                cnt++;
        }
        if (cnt < nums.size() / 2)
            return -1;
        return el;
    }
};