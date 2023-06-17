#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto aray : kArrays)
    {
        for (auto i : aray)
        {
            pq.push(i);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
