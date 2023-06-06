#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> uniqueChars;
        int maxLength = 0, leftPtr = 0, rightPtr = 0;
        while (rightPtr < s.length())
        {
            if (uniqueChars.find(s[rightPtr]) == uniqueChars.end())
            {
                uniqueChars.insert(s[rightPtr]);
                maxLength = max(maxLength, rightPtr - leftPtr + 1);
                rightPtr++;
            }
            else
            {
                uniqueChars.erase(s[leftPtr]);
                leftPtr++;
            }
        }
        return maxLength;
    }
};