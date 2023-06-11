#include <bits/stdc++.h>
using namespace std;

double maximumValue(vector<pair<int, int>> &items, int n, int W)
{
    sort(items.begin(), items.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second * 1.0 / a.first > b.second * 1.0 / b.first; });

    int totW = 0;
    double points = 0;
    for (int i = 0; i < n; i++)
    {
        if (totW + items[i].first <= W)
        {
            points += items[i].second;
            totW += items[i].first;
        }
        else
        {
            points += (double)items[i].second * (W - totW) * 1.0 / items[i].first;
            break;
        }
    }
    return points;
}