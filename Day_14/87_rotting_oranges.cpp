#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        int time = 0, mx = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j,time});
            }
        }

        if(q.empty())
            return 0;

        while(!q.empty())
        {
            vector<int> vec = q.front();
            q.pop();

            if(vec[0]-1>=0 && grid[vec[0]-1][vec[1]]==1)
            {
                grid[vec[0]-1][vec[1]]==2;
                q.push({vec[0]-1,vec[1],vec[2]+1});
            }
            if(vec[1]-1>=0 && grid[vec[0]][vec[1]-1]==1)
            {
                grid[vec[0]][vec[1]-1]==2;
                q.push({vec[0],vec[1]-1,vec[2]+1});
            }
            if(vec[0]+1<n && grid[vec[0]+1][vec[1]]==1)
            {
                grid[vec[0]+1][vec[1]]==2;
                q.push({vec[0]+1,vec[1],vec[2]+1});
            }
            if(vec[1]+1<m && grid[vec[0]][vec[1]+1]==1)
            {
                grid[vec[0]][vec[1]+1]==2;
                q.push({vec[0],vec[1]+1,vec[2]+1});
            }
            
            if(q.size()==1)
                mx = max(mx,q.front()[2]);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }

        return mx;
    }
};