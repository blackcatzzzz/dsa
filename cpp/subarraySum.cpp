// Source : https://leetcode.com/problems/subarray-sum-equals-k/

/*
560. Subarray Sum Equals K

Medium

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

#include "common.h"

// https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/qian-zhui-he-ji-qiao
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n, 0);
        // preSum[0] = 0;
        for(int i = 0; i < n; i++){
            preSum[i + 1] = preSum[i] + nums[i];
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(preSum[i] - preSum[j] == k)
                    ans++;
            }
        }

        return ans;
    }
};

// O(N), 针对上述解法优化 观察循环，preSum[i] - preSum[j] = k  -》 preSum[j] = preSum[i] - k, 且 j < i，
// 故若能得知preSum[j]的次数，只需一重循环
class Solution1{
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // map：前缀和 -> 该前缀和出现的次数
        unordered_map<int ,int> preSum;
        // base case
        preSum[0]++;

        int ans = 0, sum0_i = 0;
        for(int i = 0; i < n; i++){
            sum0_i += nums[i];
            // 这是我们想找的前缀和 nums[0..j]
            int sum0_j = sum0_i - k;
            // 如果前面有这个前缀和，则直接更新答案
            if(preSum.count(sum0_j))
                ans += preSum[sum0_j];
            // 把前缀和 nums[0..i] 加入并记录出现次数
            preSum[sum0_i]++;
        }

        return ans;
    }
};

int main(){
    vector<int> nums{1,1,1};
    int k = 2;
    Solution1 S1;
    cout << S1.subarraySum(nums, 2) << endl;
}