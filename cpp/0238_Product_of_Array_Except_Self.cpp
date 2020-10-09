/*
238. Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
*/

#include "common.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> L(n, 0);
        L[0] = 1;
        for(int i = 1; i < n; i++)
            L[i] = L[i - 1] * nums[i - 1];

        int R = 1;
        for(int i = n - 1; i >= 0; i--){
            ans[i] = L[i] * R;
            R *= nums[i];
        }
            
        return ans;
    }
};

class Solution_O_N {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> L(n, 0), R(n, 0);
        L[0] = 1;
        for(int i = 1; i < n; i++)
            L[i] = L[i - 1] * nums[i - 1];

        R[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--)
            R[i] = R[i + 1] * nums[i + 1];

        for(int i = 0; i < n; i++)
            ans[i] = L[i] * R[i];

        return ans;
    }
};


int main(){
    Solution S;
    vector<int> nums = {1,2,3,4};
    printVector(S.productExceptSelf(nums));
}