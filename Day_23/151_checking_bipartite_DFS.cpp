#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int i, vector<vector<int>> &graph, vector<int> &color, int c)
    {
        color[i] = c;
        for(auto j:graph[i])
        {
            if(color[j]==-1)
            {
                if(!dfs(j,graph,color,1-c))
                    return false;
            }
            else if(color[j]==c){
                cout << j <<"fail ";
                return false;
                }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
                if(!dfs(i,graph,color,0))
                    return false;
        }
        return true;
    }
};