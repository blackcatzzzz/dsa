/*
152. Maximum Product Subarray
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include "common.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;

        vector<int> maxProduct(n, 0),minProduct(n, 0);
        maxProduct[0] = minProduct[0] = nums[0];
        for(int i = 1; i < n; i++){
            maxProduct[i] = max(maxProduct[i - 1] * nums[i], max(minProduct[i - 1] * nums[i], nums[i]));
            minProduct[i] = min(maxProduct[i - 1] * nums[i], min(minProduct[i - 1] * nums[i], nums[i]));
        }
        
        int res = INT_MIN;
        for(auto& p:maxProduct)
            res = max(res, p);
        return res;
    }
};

int main(){
    Solution S;
    vector<int> nums = {-2,0,-1};
    cout << S.maxProduct(nums);
}