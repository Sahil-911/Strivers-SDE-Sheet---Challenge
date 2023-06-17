#include <bits/stdc++.h>
using namespace std;

vector<int> minHeap(int n, vector<vector<int>> &q)
{
    vector<int> mini;
    vector<int> temp;
    auto mn = temp.begin();
    for (int i = 0; i < n; i++)
    {
        if (q[i][0] == 0)
        {
            temp.push_back(q[i][1]);
            mn = min_element(temp.begin(), temp.end());
        }
        else
        {
            mini.push_back(*mn);
            temp.erase(mn);
        }
    }
    return mini;
}
