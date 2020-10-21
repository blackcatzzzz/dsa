/*
560. Subarray Sum Equals K
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

#include "common.h"

// 前缀和 time out
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> dp(nums.size() + 1, 0);

        int count = 0;
        for(int i = 0; i < nums.size(); i++)
            dp[i + 1] = dp[i] + nums[i];

        for(int start = 0; start < nums.size(); start++){
            for(int end = start; end < nums.size(); end++){
                if(dp[end + 1] - dp[start] == k)
                    count++;
            }
        }

        return count;
    }
};

// hash + 前缀和 O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSumFreq;
        preSumFreq[0] = 1;

        int preSum = 0, count = 0;
        for(auto& num : nums){
            preSum += num;

            count += preSumFreq[preSum - k];

            preSumFreq[preSum]++;
        }

        return count;
    }
};


int main(){
    Solution1 S;
    vector<int> nums = {1,1,1};
    int k = 2;
    cout << S.subarraySum(nums, k);
}