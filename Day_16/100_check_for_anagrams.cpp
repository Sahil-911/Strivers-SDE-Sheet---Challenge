#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
};

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        map<char, int> freq1, freq2;
        for (int i = 0; i < s.length(); i++)
        {
            freq1[s[i]]++;
            freq2[t[i]]++;
        }
        return freq1 == freq2;
    }
};

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int count[26] = {0};
        for (char x : s)
            count[x - 'a']++;
        for (char x : t)
            count[x - 'a']--;
        for (int val : count)
            if (val != 0)
                return false;
        return true;
    }
};
