#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> v1, v2;
        int i = 0;
        int j = 0;
        while (i < version1.length() || j < version2.length())
        {
            string temp1, temp2;
            while (i < version1.length() && version1[i] != '.')
            {
                temp1 += version1[i];
                i++;
            }
            i++;
            while (j < version2.length() && version2[j] != '.')
            {
                temp2 += version2[j];
                j++;
            }
            j++;
            if (!temp1.empty())
                v1.push_back(stoi(temp1));
            else
                v1.push_back(0);
            if (!temp2.empty())
                v2.push_back(stoi(temp2));
            else
                v2.push_back(0);
            if (v1.back() < v2.back())
                return -1;
            else if (v1.back() > v2.back())
                return 1;
        }
        return 0;
    }
};