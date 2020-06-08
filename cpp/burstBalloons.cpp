// Source:https://leetcode.com/problems/burst-balloons/

/*
312. Burst Balloons

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

#include "common.h"

// https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/za-qi-qiu
// dp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> points(n + 2, 0);
        points[0] = points[n + 1] = 1;

        for(int i = 1; i < n + 1; i++)
            points[i] = nums[i - 1];

        // base case dp[i][j] = 0, 其中  0 <= i <= n + 1, j <= i + 1 
        // 这种情况下，开区间 (i, j) 中间根本没有气球可以戳
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for(int i = n; i >= 0; i--){
            for(int j = i + 1; j <= n + 1; j++){
                for(int k = i + 1; k < j; k++){
                    dp[i][j] = max(dp[i][j], 
                                dp[i][k] + dp[k][j] + points[i] * points[k] * points[j]);
                }
            }
        }

        return dp[0][n + 1];
    }
};

int main(){
    Solution s;
    vector<int> nums{3,1,5,8};
    cout << s.maxCoins(nums) << endl;
}