// Source: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: Chi Zhang
// Date: 2020-05-23

/**
300. Longest Increasing Subsequence

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// O(n^2) - dynamic programming
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < dp.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int res = 0;
        for(int i = 0; i < dp.size(); i++){
            res = max(res, dp[i]);
        }

        return res;
    }
};

int main(){
    vector<int> nums{10,9,2,5,3,7,101,18};
    Solution s;
    cout << s.lengthOfLIS(nums) << endl;
}