#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& p, vector<int>& q) {
//         if (p.size() < q.size())
//         {
//             for (int i = 0; i < p.size(); i++)
//                 q.push_back(p[i]);
//             sort(q.begin(), q.end());
//             if (q.size() % 2 == 0)
//                 return (q[q.size() / 2 - 1] * 1.0 + q[q.size() / 2] * 1.0) / 2.0 ;
//             else
//                 return q[q.size() / 2] * 1.0 ;
//         }
//         else
//         {

//             for (int i = 0; i < q.size(); i++)
//                 p.push_back(q[i]);
//             sort(p.begin(), p.end());
//             if (p.size() % 2 == 0)
//                 return (p[p.size() / 2 - 1] * 1.0 + p[p.size() / 2] * 1.0) / 2.0 ;
//             else
//                 return p[p.size() / 2] * 1.0 ;
//         }
//     }
// };

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1); // ensuring that binary search happens on minimum size array

        int low = 0, high = m, medianPos = ((m + n) + 1) / 2;
        while (low <= high)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = medianPos - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1)
            {
                if ((m + n) % 2 != 0)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return 0.0;
    }
};