#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq; // DLL (push.pop->front, push.pop->back)
        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
        }

        for (int i = k; i < nums.size(); i++)
        {
            ans.push_back(nums[dq.front()]);

            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);
        return ans;
    }
};