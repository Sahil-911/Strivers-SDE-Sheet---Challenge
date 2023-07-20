#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    // {
    //     queue<pair<int,int>> q;
    //     q.push({i,j});
    //     while(!q.empty())
    //     {
    //         int row = q.front().first;
    //         int col = q.front().second;
    //         q.pop();
    //         vis[row][col] = true;
    //         if(row-1>=0 && !vis[row-1][col] && grid[row-1][col]=='1')
    //             q.push({row-1,col});
    //         if(row+1<grid.size() && !vis[row+1][col] && grid[row+1][col]=='1')
    //             q.push({row+1,col});
    //         if(col-1>=0 && !vis[row][col-1] && grid[row][col-1]=='1')
    //             q.push({row,col-1});
    //         if(col+1<grid[0].size() && !vis[row][col+1] && grid[row][col+1]=='1')
    //             q.push({row,col+1});
    //     }
    // }

    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || vis[i][j] || grid[i][j] == '0')
            return;

        vis[i][j] = true;
        dfs(i - 1, j, grid, vis);
        dfs(i, j - 1, grid, vis);
        dfs(i + 1, j, grid, vis);
        dfs(i, j + 1, grid, vis);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};