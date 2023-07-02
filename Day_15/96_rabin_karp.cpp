#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        int cnt = 0;
        string temp = a;
        while (a.size() < b.size())
        {
            a += temp;
            cnt++;
        }
        int len = b.length();
        for (int i = 0; i + len <= a.length(); i++)
        {
            if (a.substr(i, len) == b)
                return cnt + 1;
        }
        a += temp;
        cnt++;
        for (int i = 0; i + len < a.length(); i++)
        {
            if (a.substr(i, len) == b)
                return cnt + 1;
        }
        return -1;
    }
};