#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);

    int cnt = 1, mx = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (at[i] <= dt[j])
        {
            cnt++;
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
        if (cnt > mx)
            mx = cnt;
    }
    return mx;
}