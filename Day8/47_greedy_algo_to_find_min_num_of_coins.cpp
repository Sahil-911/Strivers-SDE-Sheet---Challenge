#include <bits/stdc++.h> 
using namespace std;

int findMinimumCoins(int amount) 
{
    vector<int> v = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int n=9;
    int cnt=0;
    // vector<int> ans;
    for(int i=0;i<n;i++)
    {
        while(amount>=v[i])
        {
            amount-=v[i];
            // ans.push_back(v[i]);
            cnt++;
        }
    }
    return cnt;
}
