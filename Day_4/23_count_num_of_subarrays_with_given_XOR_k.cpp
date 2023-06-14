#include <bits/stdc++.h>
using namespace std;

int solve(int *A, int n1, int B)
{
    int exor = 0;
    int maxi = 0;
    unordered_map<int, int> um;
    um[0] = 1;
    for (int i = 0; i < n1; i++)
    {
        exor ^= A[i];
        if (um.find(exor ^ B) != um.end())
            maxi += um[exor ^ B];
        else
            um[A[i]]++;
    }
    return maxi;
}