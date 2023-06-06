#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int el1 = -1, el2 = -1;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt1 == 0 && nums[i] != el2)
            {
                el1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0 && nums[i] != el1)
            {
                el2 = nums[i];
                cnt2 = 1;
            }
            else if (nums[i] == el1)
                cnt1++;
            else if (nums[i] == el2)
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == el1)
                cnt1++;
            if (nums[i] == el2)
                cnt2++;
        }
        vector<int> ans;
        if (cnt1 > nums.size() / 3)
            ans.push_back(el1);
        if (cnt2 > nums.size() / 3)
            ans.push_back(el2);
        return ans;
    }
};