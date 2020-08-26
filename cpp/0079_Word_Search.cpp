/*
79. Word Search
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

#include "common.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->m = board.size();
        this->n = board[0].size();
        this->word = word;
        used = vector<vector<bool>>(m, vector<bool>(n, false));
        direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
             if(dfs(board, i, j, 0))
                return true;
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, int i, int j, int start){
        if(board[i][j] != word[start])
            return false;

        if(start == word.size() - 1)
            return board[i][j] == word[start];

        used[i][j] = true;
        for(auto d: direction){
            int newX = i + d[0];
            int newY = j + d[1];
            if(newX < 0 || newX == m || newY < 0 || newY == n 
                || used[newX][newY])
                continue;
            
            if(dfs(board, newX, newY, start + 1))
                return true;
        }
        used[i][j] = false;

        return false;
    }

private:
    vector<vector<bool>> used;
    string word;
    vector<vector<int>> direction;
    int m;
    int n;
};

int main(){
    Solution S;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    cout << S.exist(board, "ABCCED");
}