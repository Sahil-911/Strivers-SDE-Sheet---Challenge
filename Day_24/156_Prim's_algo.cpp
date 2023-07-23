#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> vis(V,false);
        pq.push({0,0});  //{Weight,Node}
        int sum = 0;
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node])
                continue;
            vis[node] = true;
            sum += wt;
            for(auto i:adj[node])
            {
                int adjNode = i[0];
                int adjWt = i[1];
                if(!vis[adjNode])
                    pq.push({adjWt,adjNode});
            }
        }
        return sum;
    }
};