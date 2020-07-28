/*
55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5
*/

#include "common.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            farthest = max(farthest, i + nums[i]);
            if(farthest <= i)  
                return false;
            if(farthest >= nums.size() - 1)
                return true;
        }

        return farthest >= nums.size() - 1;
    }
};