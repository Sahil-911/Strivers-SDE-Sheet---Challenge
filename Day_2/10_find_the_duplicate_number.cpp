#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> u;
        for(int i=0;i<nums.size();i++)
        {
            if(u.find(nums[i])==u.end())
            u.insert(nums[i]);
            else
            return nums[i];
        }
        return 0;
    }
};