#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        double mid = (low + high) / 2;
        double x = 1;
        for (int i = 0; i < n; i++)
            x *= mid;
        if (x > m)
            high = mid - 1;
        else if (x < m)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}