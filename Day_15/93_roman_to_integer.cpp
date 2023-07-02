#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> um = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (um[s[i]] < um[s[i + 1]])
                ans -= um[s[i]];
            else
                ans += um[s[i]];
        }
        return ans;
    }
};

class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'I' && s[i + 1] == 'V')
            {
                ans += 4;
                i++;
            }
            else if (s[i] == 'I' && s[i + 1] == 'X')
            {
                ans += 9;
                i++;
            }
            else if (s[i] == 'X' && s[i + 1] == 'L')
            {
                ans += 40;
                i++;
            }
            else if (s[i] == 'X' && s[i + 1] == 'C')
            {
                ans += 90;
                i++;
            }
            else if (s[i] == 'C' && s[i + 1] == 'D')
            {
                ans += 400;
                i++;
            }
            else if (s[i] == 'C' && s[i + 1] == 'M')
            {
                ans += 900;
                i++;
            }
            else if (s[i] == 'M')
                ans += 1000;
            else if (s[i] == 'D')
                ans += 500;
            else if (s[i] == 'C')
                ans += 100;
            else if (s[i] == 'L')
                ans += 50;
            else if (s[i] == 'X')
                ans += 10;
            else if (s[i] == 'V')
                ans += 5;
            else if (s[i] == 'I')
                ans += 1;
            else
                continue;
        }
        return ans;
    }
};