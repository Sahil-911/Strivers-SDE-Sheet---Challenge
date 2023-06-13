#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     string getPermutation(int n, int k)
//     {
//         vector<int> nums;
//         for (int i = 1; i <= n; i++)
//             nums.push_back(i);
//         for (int i = 1; i < k; i++)
//             next_permutation(nums.begin(), nums.end());
//         string ans;
//         for (int i = 0; i < n; i++)
//             ans += to_string(nums[i]);
//         return ans;
//     }
// };

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> nums;
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            fact = i * fact;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        k--;
        while (true)
        {
            ans += to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if (nums.size() == 0)
                break;
            k = k % fact;
            fact = fact / nums.size();
        }
        return ans;
    }
};