// Source : https://leetcode.com/problems/maximum-subarray/

/*
53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include "common.h"

// https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/zui-da-zi-shu-zu-1
// dp O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        // base case
        dp[0] = nums[0];
        for(int i = 1; i < n; i++)
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);

        int res = INT_MIN;
        for(int i = 0; i < n; i++)
            res = max(res, dp[i]);

        return res;
    }
};

// O(1)
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // base case
        int maxEndingHere = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < n; i++){
            // dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            maxEndingHere = max(nums[i], maxEndingHere  + nums[i]);
            maxSum = max(maxSum, maxEndingHere);
        }

        return maxSum;       
    }
};

int main(){
    Solution s;
    vector<int> nums{-2, 1};
    cout << s.maxSubArray(nums) << endl;
}