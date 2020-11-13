/*
37. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/

#include "common.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        row = vector<vector<bool>>(9, vector<bool>(9, false));
        col = vector<vector<bool>>(9, vector<bool>(9, false));
        box = vector<vector<bool>>(9, vector<bool>(9, false));
        valid = false;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c == '.')
                    spaces.push_back(make_pair(i, j));
                else{
                    row[i][c - '0' - 1] = true;
                    col[j][c - '0' - 1] = true;
                    box[i / 3 * 3 + j / 3][c - '0' - 1] = true;
                }
            }
        }

        dfs(board, 0);
    }

    void dfs(vector<vector<char>>& board, int index){
        if(index == spaces.size()){
            valid = true;
            return;
        }

        int i = spaces[index].first;
        int j = spaces[index].second;

        for(int k = 1; k <= 9 && !valid; k++){
            if(row[i][k - 1] || col[j][k - 1] || box[i / 3 * 3 + j / 3][k - 1])
                continue;

            row[i][k - 1] = true;
            col[j][k - 1] = true;
            box[i / 3 * 3 + j / 3][k - 1] = true;

            board[i][j] = k + '0';
            dfs(board, index + 1);

            row[i][k - 1] = false;
            col[j][k - 1] = false;
            box[i / 3 * 3 + j / 3][k - 1] = false;
        }
    }

private:
    bool valid;
    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<bool>> box;
    vector<pair<int,int>> spaces;
};

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution S;
    S.solveSudoku(board);
}