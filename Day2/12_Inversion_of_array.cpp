#include <bits/stdc++.h>
using namespace std;

long long getInversions(long long *arr, int n)
{
    long long cnt = 0;
    int l = 0, r = l + 1;
    while (l < n - 1)
    {
        if (arr[l] > arr[r])
            cnt++;
        r++;
        if (r == n)
        {
            l++;
            r = l + 1;
        }
    }
    return cnt;
}
