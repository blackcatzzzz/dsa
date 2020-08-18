/*
34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non decreasing array.
-10^9 <= target <= 10^9
*/

#include "common.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{left_bound(nums, target), right_bound(nums, target)};
    }

public:
    int left_bound(vector<int>& nums, int target){
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target)
                hi = mid - 1;
            else if(target < nums[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        if(lo == nums.size() || nums[lo] != target)
            return -1;

        return lo;
    }

    int right_bound(vector<int>& nums, int target){
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target)
                lo = mid + 1;
            else if(target < nums[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        if(hi == -1 || nums[hi] != target)
            return -1;

        return hi;
    }
};

int main(){
    Solution S;
    vector<int> nums{};
    int target = 1;
    printVector(S.searchRange(nums, target));
}