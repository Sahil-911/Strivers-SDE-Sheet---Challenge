#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> v = {{1}};
    if (n == 1)
        return v;
    v.push_back({1, 1});
    if (n == 2)
        return v;
    int k = 3;
    while (k <= n)
    {
        vector<long long int> temp;
        for (int i = 0; i < k; i++)
        {
            if (i == 0 || i == k - 1)
            {
                temp.push_back(1);
                continue;
            }
            temp.push_back(v[k - 2][i] + v[k - 2][i - 1]);
        }
        v.push_back(temp);
        k++;
    }
    return v;
}
