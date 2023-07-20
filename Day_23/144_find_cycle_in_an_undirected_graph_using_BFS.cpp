#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
            if(indegree[i]==0)
                q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto i:adj[node])
            {
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);                    
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]!=0)
                return false;
        }
        return true;
    }
};