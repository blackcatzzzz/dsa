/*
189. Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 2 * 10^4
It's guaranteed that nums[i] fits in a 32 bit-signed integer.
k >= 0
*/

#include "common.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        for(int start = 0, count = 0; count < nums.size();start++){
            int pre = nums[start];
            int cur = start;
            do{
                int next = (cur + k) % nums.size();
                int tmp = nums[next];
                nums[next] = pre;
                pre = tmp;
                cur = next;
                count++;
            }while(cur != start);
        }
    }
};

class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        if(k % nums.size() == 0)
            return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main(){
    Solution S;
    vector<int> nums = {1,2,3,4};
    S.rotate(nums,2);
    printVector(nums);
}