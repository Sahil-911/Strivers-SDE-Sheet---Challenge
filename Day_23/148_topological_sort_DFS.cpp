#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int i, vector<int> adj[],vector<bool> &vis, stack<int> &st)
	{
	    vis[i] = true;
	    for(int j:adj[i])
	    {
	        if(!vis[j])
	            dfs(j,adj,vis,st);
	    }
	    st.push(i);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<bool> vis(V);
	    for(int i=0;i<V;i++)
        {
            if(!vis[i])
                dfs(i,adj,vis,st);
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
	}
};