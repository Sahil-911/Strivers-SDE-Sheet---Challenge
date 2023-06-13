#include <bits/stdc++.h>
using namespace std;

bool canPlace(int ind, vector<int> &color, int col, int n, vector<vector<int>> &graph)
{
    for (int k = 0; k < n; k++)
    {
        if (ind != k && graph[k][ind] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}

bool help(int ind, vector<int> &color, int m, int n, vector<vector<int>> &graph)
{
    if (ind == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (canPlace(ind, color, i, n, graph))
        {
            color[ind] = i;
            if (help(ind + 1, color, m, n, graph))
                return true;
            color[ind] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &graph, int m)
{
    int n = graph.size();
    vector<int> color(n, 0);
    if (help(0, color, m, n, graph))
        return "YES";
    return "NO";
}