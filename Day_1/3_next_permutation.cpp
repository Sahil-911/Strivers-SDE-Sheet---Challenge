// #include <bits/stdc++.h>
// using namespace std;

// vector<int> nextPermutation(vector<int> &permutation, int n)
// {
//     next_permutation(permutation.begin(),permutation.end());
//     return permutation;
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &a, int n)
{
  int x = -1;
  for (int i = n - 2; i >= 0; i--)
  {
    if (a[i] < a[i + 1])
    {
      x = i;
      break;
    }
  }
  if (x == -1)
  {
    reverse(a.begin(), a.end());
    return a;
  }
  int y = -1;
  for (int i = n - 1; i > x; i--)
  {
    if (a[i] > a[x])
    {
      y = i;
      break;
    }
  }
  swap(a[x], a[y]);
  reverse(a.begin() + x + 1, a.end());
  return a;
}