#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int lm = height[left], rm = height[right];
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] > lm)
                    lm = height[left];
                else
                    res += lm - height[left];
                left++;
            }
            else
            {
                if (height[right] > rm)
                    rm = height[right];
                else
                    res += rm - height[right];
                right--;
            }
        }
        return res;
    }
};