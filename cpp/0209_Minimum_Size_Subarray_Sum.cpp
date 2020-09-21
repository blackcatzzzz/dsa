/*
209. Minimum Size Subarray Sum
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/

#include "common.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        int start = 0, end = 0;
        int ans = INT_MAX, sum = 0;
        while(end < n){
            sum += nums[end];
            while(sum >= s){
                ans = min(end - start + 1, ans);
                sum -= nums[start];
                start++;
            }
            end++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main(){
    Solution S;
    vector<int> nums = {2,3,1,2,4,3};
    cout << S.minSubArrayLen(7, nums);
}