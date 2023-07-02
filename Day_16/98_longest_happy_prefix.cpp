#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string a)
{
    int i = 0, j = a.length() - 1;
    while (i < j)
    {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string a)
{
    int len = a.length();
    while (len)
    {
        if (isPalindrome(0, len - 1, a))
            return a.length() - len;
        len--;
    }
    return 0;
}
