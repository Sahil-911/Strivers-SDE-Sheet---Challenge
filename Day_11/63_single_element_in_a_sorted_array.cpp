#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size() % 2;
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[nums.size() - 1] != nums[nums.size() - 2])
            return nums[nums.size() - 1];

        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (mid != 0 && nums[mid] == nums[mid - 1])
            {
                if (mid % 2 == 0)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if (mid != nums.size() - 1 && nums[mid] == nums[mid + 1])
            {
                if (mid % 2 == 0)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
                return nums[mid];
        }
        return nums[low];
    }
};