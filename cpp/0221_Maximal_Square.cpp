/*
221. Maximal Square
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

#include "common.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSide = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0')
                    continue;

                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;

                maxSide = max(maxSide, dp[i][j]);
            }
        }

        return maxSide * maxSide;
    }
};

int main(){

}