#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> dp;

    bool isPalindrome(string s)
    {
        int i=0, j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, string str)
    {
        if(i==str.length())
        {
            return 0;
        }

        if(dp[i]!=-1)
            return dp[i];
            
        int minCost = 1e6;
        
        for(int j=i;j<str.length();j++)
        {
            if(isPalindrome(str.substr(i,j-i+1)))
            {
                int cost = 1+solve(j+1,str);
                minCost = min(minCost,cost);
            }
        }
        
        return dp[i] = minCost;
}

    int palindromicPartition(string str)
    {
        dp.resize(str.length(),-1);
        return solve(0,str)-1;
    }
};