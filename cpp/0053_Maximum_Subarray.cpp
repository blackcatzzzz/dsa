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

// dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEndingHere = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maxEndingHere = max(nums[i], nums[i] + maxEndingHere);
            maxSum = max(maxSum, maxEndingHere);
        }

        return maxSum;
    }
};

// 自己的朴素方法
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int curSum = 0;
        for(auto num : nums){
            if(num < 0){
                curSum = curSum + num < 0 ? num : curSum + num ;
            }else {
                if(curSum < 0)
                    curSum = num;
                else
                    curSum = curSum + num;
            }
                
            res = max(res, curSum);
        }

        return res;
    }
};

int main(){
    Solution S;
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout << S.maxSubArray(nums) << endl;
}