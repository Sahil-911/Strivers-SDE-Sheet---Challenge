#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.

    void dfs(int i, vector<int> adj[], vector<bool> &vis, vector<int> &temp)
    {
        vis[i] = true;

        for (auto j : adj[i])
        {
            if (!vis[j])
            {
                temp.push_back(j);
                dfs(j, adj, vis, temp);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int> temp;
        temp.push_back(0);
        for (int i = 0; i < V; i++)
            if (!vis[i])
                dfs(i, adj, vis, temp);
        return temp;
    }
};