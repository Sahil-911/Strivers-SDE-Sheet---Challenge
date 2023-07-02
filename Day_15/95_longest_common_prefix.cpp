#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end(), [](string a, string b)
             { return a.length() < b.length(); });
        string temp = strs[0];
        while (temp.size() > 0)
        {
            int diff = 0;
            for (int i = 0; i < strs.size(); i++)
            {
                if (temp != strs[i].substr(0, temp.size()))
                    diff = 1;
            }
            if (!diff)
                return temp;
            temp.resize(temp.size() - 1);
        }
        return "";
    }
};