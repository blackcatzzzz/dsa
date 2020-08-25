/*
63. Unique Paths II
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

#include "common.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n && !obstacleGrid[i][0]; i++)
            dp[i][0] = obstacleGrid[i][0] ? 0 : 1;

        for(int j = 0; j < m && !obstacleGrid[0][j]; j++)
            dp[0][j] = 1;

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(obstacleGrid[i][j])
                    continue;
                dp[i][j] = (obstacleGrid[i - 1][j] ? 0 : dp[i - 1][j]) + (obstacleGrid[i][j - 1] ? 0 : dp[i][j - 1]);
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main(){
    vector<vector<int>> obstacleGrid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    obstacleGrid = {{0,0},{0,1}};

    Solution S;
    cout << S.uniquePathsWithObstacles(obstacleGrid);
}