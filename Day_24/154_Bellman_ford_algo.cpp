#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> minDist(V,1e8);
        minDist[S]=0;
        for(int i=0;i<V-1;i++)
        {
            for(int j=0;j<edges.size();j++)
            {
                if(minDist[edges[j][0]]!=1e8)
                {
                    int from = edges[j][0];
                    int to = edges[j][1];
                    int adjWeight = edges[j][2];
                    if(minDist[from]+adjWeight<minDist[to])
                        minDist[to] = minDist[from]+adjWeight;
                }
            }
        }
        for(int j=0;j<edges.size();j++)
        {
            if(minDist[edges[j][0]]!=1e8)
            {
                int from = edges[j][0];
                int to = edges[j][1];
                int adjWeight = edges[j][2];
                if(minDist[from]+adjWeight<minDist[to])
                {
                    minDist = {-1};
                    break;
                }
            }
        }
        return minDist;
    }
};