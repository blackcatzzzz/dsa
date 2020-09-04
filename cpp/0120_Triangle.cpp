/*
120. Triangle
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

#include "common.h"

// dp O(n) 空间优化
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m == 0)
            return 0;
        vector<int> dp(m, 0);
        for(int j = 0; j < m; j++)
            dp[j] = triangle[m - 1][j];
        
        for(int i = m - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }   
        }

        return dp[0];
    }
};

// dp
class Solution_DP {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m == 0)
            return 0;
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for(int j = 0; j < m; j++)
            dp[m - 1][j] = triangle[m - 1][j];
        
        for(int i = m - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }   
        }

        return dp[0][0];
    }
};

// time out
class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        m = triangle.size();
        if(m == 0)
            return 0;
        dfs(triangle, 0, 0);
        return res;
    }

private:
    void dfs(vector<vector<int>>& triangle, int i, int j){
        if(j >= triangle[i].size())
            return;
        
        sum += triangle[i][j];

        if(i == m - 1){
            res = min(res, sum);
            sum -= triangle[i][j];
            return;
        }

        dfs(triangle, i + 1, j);
        if(j <= i)
            dfs(triangle, i + 1, j + 1);

        sum -= triangle[i][j];
    }

private:
    int res = INT_MAX;
    int sum = 0;
    int m = 0;
};

int main(){
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    Solution S;
    cout << S.minimumTotal(triangle);
}