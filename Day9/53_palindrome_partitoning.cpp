#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int start, int end, string s)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void help(int ind, string s, vector<vector<string>> &ans, vector<string> &tmp)
    {
        if (ind == s.length())
        {
            ans.push_back(tmp);
            return;
        }
        for (int i = ind; i < s.length(); i++)
        {
            if (isPalindrome(ind, i, s))
            {
                tmp.push_back(s.substr(ind, i - ind + 1));
                help(i + 1, s, ans, tmp);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> tmp;
        help(0, s, ans, tmp);
        return ans;
    }
};