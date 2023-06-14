#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:

//     bool canPlace(int row, int col, vector<string> &board)
//     {
//         int r=row;
//         int c=col;
//         while(row>=0 && col>=0)
//         {
//             if(board[row][col]=='Q')
//                 return false;
//             row--;
//             col--;
//         }
//         row=r;
//         col=c;
//         while(col>=0)
//         {
//             if(board[row][col]=='Q')
//                 return false;
//             col--;
//         }
//         row=r;
//         col=c;
//         while(row<board.size() && col>=0)
//         {
//             if(board[row][col]=='Q')
//                 return false;
//             row++;
//             col--;
//         }
//         return true;
//     }

//     void solve(int col, vector<string> &board, vector<vector<string>> &ans,int n)
//     {
//         if(col==n)
//         {
//             ans.push_back(board);
//             return ;
//         }

//         for(int row=0;row<n;row++)
//         {
//             if(canPlace(row,col,board))
//             {
//                 board[row][col]='Q';
//                 solve(col+1,board,ans,n);
//                 board[row][col]='.';
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board (n,string (n,'.'));
//         solve(0,board,ans,n);
//         return ans;
//     }
// };

class Solution {
public:

    void solve(int col, vector<string> &board, vector<int> &leftrow, vector<int> &lowerdiagonal, vector<int> &upperdiagonal, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (leftrow[row]==0 && lowerdiagonal[row + col]==0 && upperdiagonal[row - col + n - 1]==0)
            {
                leftrow[row] = 1;
                lowerdiagonal[row + col] = 1;
                upperdiagonal[row - col + n - 1] = 1;
                board[row][col] = 'Q';

                solve(col + 1, board, leftrow, lowerdiagonal, upperdiagonal, ans, n);

                // Revert the changes
                leftrow[row] = 0;
                lowerdiagonal[row + col] = 0;
                upperdiagonal[row - col + n - 1] = 0;
                board[row][col] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<int> leftrow(n,0), lowerdiagonal(2*n-1,0), upperdiagonal(2*n-1,0);
        solve(0,board,leftrow,lowerdiagonal,upperdiagonal,ans,n);
        return ans;
    }
};