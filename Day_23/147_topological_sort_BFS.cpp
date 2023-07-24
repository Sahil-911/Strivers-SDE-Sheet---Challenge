#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int> ans;
	    vector<int> inDegree(V,0);
        for(int i=0;i<V;i++)
            for(auto j:adj[i])
                inDegree[j]++;
        queue<int> q;
        for(int i=0;i<V;i++)
            if(inDegree[i]==0)
                q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adj[node])
            {
                inDegree[i]--;
                if(inDegree[i]==0)
                    q.push(i);
            }
        }
        return ans;
	}
};