#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> dist;
        dist.insert({0,S});
        vector<int> ans(V,INT_MAX);
        while(!dist.empty())
        {
            int node = dist.begin()->second;
            int d = dist.begin()->first;
            dist.erase(dist.begin());
            for(auto i:adj[node])
            {
                if(d+i[1]<ans[i[0]])
                {
                    ans[i[0]] = d+i[1];
                    dist.insert({ans[i[0]],i[0]});
                }
            }
        }
        return ans;
    }
};
// class Solution
// {
// 	public:
// 	//Function to find the shortest distance of all the vertices
//     //from the source vertex S.
//     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
//     {
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//         vector<int> mini(V,INT_MAX);
//         mini[S] = 0;
//         pq.push({0,S});
//         while(!pq.empty())
//         {
//             int ver = pq.top().second;
//             int dis = pq.top().first;
//             pq.pop();
//             for(auto i:adj[ver])
//             {
//                 int edgeWeight = i[1];
//                 int adjNode = i[0];
//                 if(dis+edgeWeight<mini[adjNode])
//                 {
//                     mini[adjNode] = dis+edgeWeight;
//                     pq.push({mini[adjNode],adjNode});
//                 }
//             }
//         }
//         return mini;
//     }
// };