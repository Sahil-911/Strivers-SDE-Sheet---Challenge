#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& v, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<v.size();i++)
        {
            int b=k-v[i];
            if(m.find(b)!=m.end())
                return {m[b],i};
            m[v[i]]=i;
        }
        return {};
    }
};