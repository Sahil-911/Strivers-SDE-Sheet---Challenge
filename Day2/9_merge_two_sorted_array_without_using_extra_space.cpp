#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1, p2 = 0;
        while (p1 >= 0 && p2 < n)
        {
            if (nums1[p1] < nums2[p2])
                swap(nums1[p1--], nums2[p2++]);
            else
                break;
        }
    }
};