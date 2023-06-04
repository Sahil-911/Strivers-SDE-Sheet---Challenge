#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
  int l0 = -1, l1 = -1, l2 = -1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      l2++;
      l1++;
      l0++;
      arr[l2] = 2;
      arr[l1] = 1;
      arr[l0] = 0;
    }
    else if (arr[i] == 1)
    {
      l2++;
      l1++;
      arr[l2] = 2;
      arr[l1] = 1;
    }
    else
    {
      l2++;
      arr[l2] = 2;
    }
  }
}
