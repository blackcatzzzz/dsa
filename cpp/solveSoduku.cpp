// Source : https://leetcode.com/problems/sudoku-solver/

/*
37. Sudoku Solver

Hard

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/

#include "common.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() < 9 || board[0].size() < 9)
            return;
        helper(board, 0 , 0);
    }

    bool helper(vector<vector<char>>& board, int i, int j){
        int m = 9, n = 9;

        // 穷举到最后一列的话就换到下一行重新开始
        if(j == n){
            return helper(board, i + 1, 0);
        }

        if(i == m)
            // 找到一个可行解，触发 base case
            return true;

        // 如果有预设数字，不用我们穷举
        if(board[i][j] != '.')
            return helper(board, i, j + 1); 

        
        for(char ch = '1'; ch <= '9'; ch++){
            if(!isValid(board, i, j, ch))
                continue;

            // 做选择
            board[i][j] = ch;

            // 进入下一层决策
            if(helper(board, i, j + 1))
                return true; // 如果找到一个可行解，立即结束

            // 撤销选择
            board[i][j] = '.';
        }

        // 穷举完 1~9，依然没有找到可行解，此路不通
        return false;
    }

    // 判断 board[i][j] 是否可以填入 ch
    bool isValid(vector<vector<char>>& board, int r, int c, char ch){
        for(int i = 0; i < 9; i++){
            if(board[r][i] == ch) return false; // 判断同一行是否重复
            if(board[i][c] == ch) return false; // 判断同一列是否重复
            if(board[(r/3)*3 + i/3][(c/3)*3 + i%3] == ch)   // 判断3*3的格子中是否重复
                return false;
        }

        return true;
    }
};

int main(){
    vector<vector<int>> a(3, vector<int>(2, 0));
    cout << a.size() << " " << a[0].size() << endl;
    int r = 1, c = 1;
    for(int i = 0; i < 9; i++){
        cout << (r/3)*3 + i/3 << " " << (c/3)*3 + i%3 << endl;
    }
}