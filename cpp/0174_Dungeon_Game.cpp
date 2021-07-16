/*
174. Dungeon Game
The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

 

Example 1:


Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
Example 2:

Input: dungeon = [[0]]
Output: 1
 

Constraints:

m == dungeon.length
n == dungeon[i].length
1 <= m, n <= 200
-1000 <= dungeon[i][j] <= 1000
*/

#include "common.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memory = vector<vector<int>>(m , vector<int>(n, INT_MAX));

        return dfs(dungeon, 0, 0);
    }

    int dfs(vector<vector<int>>& dungenon, int r, int c){
        if(r >= m || r < 0 || c >= n || c < 0)
            return INT_MAX;

        if(memory[r][c] != INT_MAX)
            return memory[r][c];
            
        if(r == m - 1 && c == n - 1){
            return max(1 - dungenon[r][c], 1);
        }
            
        memory[r][c] = max(min(dfs(dungenon, r, c + 1), dfs(dungenon, r + 1, c)) - dungenon[r][c], 1);
        return memory[r][c];
    }

private:
    int m = 0, n = 0;
    vector<vector<int>> memory;
};


int main(){
    Solution S;
    vector<vector<int>> dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}}; // 7
    // vector<vector<int>> dungeon = {{0,-5},{0,0}}; // 1
    cout << S.calculateMinimumHP(dungeon);
}