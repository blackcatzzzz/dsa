/*
153. Find Minimum in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

#include "common.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
            
        if(nums.size() == 1)
            return nums[0];
        
        int left = 0, right = nums.size() - 1;
        if(nums[right] > nums[0])
            return nums[0];

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[mid + 1])
                return nums[mid + 1];

            if(nums[mid - 1] > nums[mid])
                return nums[mid];

            if(nums[mid] > nums[0])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};

int main(){
    Solution S;
    vector<int> nums = {3,4,5,1,2};
    cout << S.findMin(nums);
}