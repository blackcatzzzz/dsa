/*
200. Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

#include "common.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if(m == 0)  return 0;
        n = grid[0].size();
        int ans = 0;
        // visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0')
                    continue;
                ans++;
                dfs(grid, i, j);
            }
        }

        return ans;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n
            || grid[i][j] == '0')
            return;

        // visited[i][j] = true;
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

private:
    // vector<vector<bool>> visited;
    int m;
    int n;
};

int main(){
    Solution S;
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}     
    };

    cout << S.numIslands(grid);
}