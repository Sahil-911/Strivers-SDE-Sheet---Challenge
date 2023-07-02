#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        while (i < s.length() && s[i] == ' ')
            i++;
        if (i == s.length() || (!isdigit(s[i]) && s[i] != '-' && s[i] != '+'))
            return 0;

        int sign = 1;
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
            i++;

        long long ans = 0;
        while (i < s.length() && isdigit(s[i]))
        {
            ans = ans * 10 + (s[i] - '0');
            if (sign * ans < INT_MIN)
                return INT_MIN;
            else if (sign * ans > INT_MAX)
                return INT_MAX;
            i++;
        }
        return sign * ans;
    }
};