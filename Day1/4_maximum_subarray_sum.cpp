#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
  long long sum = arr[0];
  long long mx = arr[0];
  for (int i = 1; i < n; i++)
  {
    sum = max((long long)arr[i], sum + arr[i]);
    mx = max(mx, sum);
  }
  if (mx < 0)
    return 0;
  return mx;
}