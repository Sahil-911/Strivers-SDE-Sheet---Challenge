#include <bits/stdc++.h>
using namespace std;

int cntlesser(int val, vector<int> row)
{
    int low = 0, high = row.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (row[mid] <= val)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int getMedian(vector<vector<int>> &matrix)
{
    int low = 1, high = 1e5;
    int n = matrix.size();
    int m = matrix[0].size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += cntlesser(mid, matrix[i]);
        }
        if (cnt <= m * n / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}