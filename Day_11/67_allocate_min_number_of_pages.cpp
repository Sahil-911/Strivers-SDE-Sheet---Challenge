#include <bits/stdc++.h>
using namespace std;

bool isPossible(int barrier, vector<int> &A, int B)
{
    int allocated = 1; // Start with 1, as the first student gets allocated
    int pages = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > barrier)
            return false;
        if (pages + A[i] > barrier)
        {
            allocated++;
            pages = A[i];
            if (allocated > B)
                return false;
        }
        else
        {
            pages += A[i];
        }
    }
    return true;
}

int books(vector<int> &A, int B)
{
    int n1 = A.size();
    int high = accumulate(A.begin(), A.end(), 0);
    int low = *min_element(A.begin(), A.end());
    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(mid, A, B))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}
