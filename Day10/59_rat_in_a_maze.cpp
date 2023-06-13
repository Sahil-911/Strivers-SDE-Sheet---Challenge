#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int row, int col, vector<vector<int>> &m, int n)
    {
        if (row >= 0 && col >= 0 && row < n && col < n && m[row][col] == 1)
            return true;
        return false;
    }

    void help(int row, int col, vector<vector<int>> &m, int n, string &temp, vector<string> &ans)
    {
        if (row < 0 || col < 0 || row >= n || col >= n)
            return;

        if (row == n - 1 && col == n - 1 && m[row][col] == 1)
        {
            ans.push_back(temp);
            return;
        }

        if (check(row, col, m, n))
        {
            m[row][col] = 0; // Mark the cell as visited

            temp.push_back('U');
            help(row - 1, col, m, n, temp, ans);
            temp.pop_back();

            temp.push_back('D');
            help(row + 1, col, m, n, temp, ans);
            temp.pop_back();

            temp.push_back('L');
            help(row, col - 1, m, n, temp, ans);
            temp.pop_back();

            temp.push_back('R');
            help(row, col + 1, m, n, temp, ans);
            temp.pop_back();

            m[row][col] = 1; // Mark the cell as unvisited
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        string temp;
        help(0, 0, m, n, temp, ans);
        return ans;
    }
};
