#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlace(int row, int col, char val, vector<vector<char>> &board)
    {
        // check col
        for (int r = 0; r < 9; r++)
        {
            if (board[r][col] == val)
                return false;
        }

        // check row
        for (int c = 0; c < 9; c++)
        {
            if (board[row][c] == val)
                return false;
        }

        // check in 3x3 sub-board
        int r = row / 3;
        int c = col / 3;
        for (int i = r * 3; i < r * 3 + 3; i++)
        {
            for (int j = c * 3; j < c * 3 + 3; j++)
            {
                if (board[i][j] == val)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board, int row, int col)
    {

        if (row == 9)
            return true;

        if (col == 9)
            return solve(board, row + 1, 0);

        if (board[row][col] != '.')
            return solve(board, row, col + 1);

        for (char val = '1'; val <= '9'; val++)
        {
            if (canPlace(row, col, val, board))
            {
                board[row][col] = val;
                if (solve(board, row, col + 1))
                    return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board, 0, 0);
    }
};