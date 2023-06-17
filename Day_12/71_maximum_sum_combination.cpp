#include <bits/stdc++.h>
using namespace std;

// vector<int> solve(vector<int> &A, vector<int> &B, int C)
// {
//     priority_queue<int, vector<int>, greater<int>> pq;
//     sort(A.begin(), A.end());
//     sort(B.begin(), B.end());
//     for (int i = A.size() - 1; i >= 0; i--)
//     {
//         for (int j = B.size() - 1; j >= 0; j--)
//         {
//             pq.push(A[i] + B[j]);
//             if (pq.size() == C + 1)
//                 pq.pop();
//         }
//     }
//     vector<int> ans;
//     while (!pq.empty())
//     {
//         ans.push_back(pq.top());
//         pq.pop();
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }


vector<int> solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({A[A.size()-1]+B[B.size()-1],{A.size()-1,B.size()-1}});
    set<pair<int,int>> visited;
    vector<int> ans;
    while(C--)
    {
        int top=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        pq.pop();
        ans.push_back(top);
        if(i!=0 && visited.find({i-1,j})==visited.end())
        {
            pq.push({A[i-1]+B[j],{i-1,j}});
            visited.insert({i-1,j});
        }
        if(j!=0 && visited.find({i,j-1})==visited.end())
        {
            pq.push({A[i]+B[j-1],{i,j-1}});
            visited.insert({i,j-1});
        }
    }
    return ans;
}