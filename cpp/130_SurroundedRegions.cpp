
/*
130. Surrounded Regions
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

#include "common.h"

// https://labuladong.gitbook.io/algo/gao-pin-mian-shi-xi-lie/unionfind-suan-fa-ying-yong
// union find set solution
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        int dummy = m * n;
        UF uf(m * n + 1);

        // 首列和尾列'O'
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O')
                uf.unionSet(i * n, dummy);

            if(board[i][n - 1] == 'O')
                uf.unionSet(i * n + n - 1, dummy);
        }
        
        // 首行和尾行的'O'
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O')
                uf.unionSet(j, dummy);

            if(board[m - 1][j] == 'O')
                uf.unionSet( (m - 1) * n + j, dummy);
        }

        vector<vector<int>> d{{1,0},{0,1},{-1,0},{0,-1}};
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(board[i][j] == 'O'){
                    for(int k = 0; k < 4; k++){
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if(board[x][y] == 'O')
                            uf.unionSet(i * n + j, x * n + y);
                    }
                }
            }
        }

        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(board[i][j] == 'O')
                    if(!uf.connected(i * n + j, dummy))
                        board[i][j] = 'X';
            }
        }

        return;
    }

    class UF {
    public:
        UF(int n): _count(n), parent(n, 0), size(n, 1){
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        void unionSet(int p, int q){
            int rootP = find(p);
            int rootQ = find(q);
            if(rootP == rootQ)
                return;
            if(size[rootP] > size[rootQ]){
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            }else{
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }

            _count--;
        }

        bool connected(int p, int q){
            int rootP = find(p);
            int rootQ = find(q);
            return rootP == rootQ;
        }

        int find(int x){
            while(parent[x] != x){
                parent[x] = parent[parent[x]];
                x = parent[x];
            }

            return x;
        }

        int count(){
            return this->_count;
        }

    private:
        int _count; // 连通分量
        vector<int> parent; // 根节点
        vector<int> size;   // 大小
    };
};

// DFS
class Solution_DFS {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                bool isEdge = i == 0 || i == m - 1 || j == 0 || j == n - 1;
                if(isEdge && board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
        || board[i][j] == 'X' || board[i][j] == '#' )
            return;

        board[i][j] = '#';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
};


int main(){
    vector<vector<char>> board{{'X','O','X','O','X','O'},{'O','X','O','X','X','X'},{'X','X','X','X','X','O'},{'O','X','O','X','O','X'}};
    Solution_DFS S;
    S.solve(board);
    getchar();
}