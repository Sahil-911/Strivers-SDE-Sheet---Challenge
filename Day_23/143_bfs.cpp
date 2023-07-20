#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        vector<int> temp;
        while (!q.empty())
        {
            // int size = q.size();
            // while(size--)
            // {
            int node = q.front();
            q.pop();
            temp.push_back(node);
            for (auto i : adj[node])
            {
                if (!vis[i])
                {
                    vis[i] = true;
                    q.push(i);
                }
            }
            // }
        }
        return temp;
    }
};