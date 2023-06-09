#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++)
            if(nums[i]!=nums[i-1])
                ans.push_back(nums[i]);
        nums=ans;
        return nums.size();
    }
};