// Source : https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/hui-su-suan-fa-xiang-jie-xiu-ding-ban


#include "common.h"

vector<vector<string>> res;

/* 是否可以在 board[row][col] 放置皇后？ */
bool isValid(vector<string>& board, int row, int col){
    int n = board.size();
    // 检查列是否有皇后互相冲突
    for (int i = 0; i < n; i++) {
        if(board[i][col] == 'Q')
            return false;
    }

    // 检查右上方是否有皇后互相冲突
    for(int i = row - 1, j = col + 1; i >= 0 && j < n;i--, j++){
        if(board[i][j] == 'Q')
            return false;
    }

    // 检查左上方是否有皇后互相冲突
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0;i--, j--){
        if(board[i][j] == 'Q')
            return false;
    }

    return true;
}

void backtrack(vector<string>& board, int row){
    // 触发结束条件
    if(row == board.size()){
        res.push_back(board);
        return;
    }

    int n = board[row].size();
    for(int col = 0; col < n; col++){
        // 排除不合法选择
        if(!isValid(board, row, col))
            continue;
        
        // 做选择
        board[row][col] = 'Q';
        // 进入下一行决策
        backtrack(board, row + 1);
        // 撤销选择
        board[row][col] = '.';
    }
}

/* 输入棋盘边长 n，返回所有合法的放置 */
vector<vector<string>> solveNQueens(int n){
    // '.' 表示空，'Q' 表示皇后，初始化空棋盘
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0);
    return res;
}

int main(){
    vector<vector<string>> res = solveNQueens(8);
    for(int i = 0; i < res.size();i++){
        printf("%d:\n", i);
        for(string row:res[i])
            cout << row << endl;
        cout << endl;
    }
}