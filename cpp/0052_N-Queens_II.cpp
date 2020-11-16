/*
52. N-Queens II
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include "common.h"

class Solution {
public:
    int totalNQueens(int n) {
        ans = 0;
        vector<string> board(n, string(n, '.'));
        backtrace(board, 0);
        return ans;
    }

private:
    bool isValid(vector<string>& board, int row, int col){
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q')
                return false;
        }

        for(int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q')
                return false;
        }

        for(int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++){
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void backtrace(vector<string>& board, int row){
        if(row == board.size()){
            ans++;
            return;
        }

        for(int j = 0; j < board.size(); j++){
            if(!isValid(board, row, j))
                continue;

            board[row][j] = 'Q';
            backtrace(board, row + 1);
            board[row][j] = '.';
        }
    }

private:
    int ans;
};

int main(){

}