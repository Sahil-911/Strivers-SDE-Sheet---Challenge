#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int quickselect(vector<int> &nums, int l, int r, int k)
    {
        int pivot = nums[r];
        int p = l;
        for (int i = l; i < r; i++)
        {
            if (nums[i] <= pivot)
            {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[p], nums[r]);
        if (p > k)
            return quickselect(nums, l, p - 1, k);
        else if (p < k)
            return quickselect(nums, p + 1, r, k);
        else
            return nums[p];
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        k = nums.size() - k;
        return quickselect(nums, 0, nums.size() - 1, k);
    }
};