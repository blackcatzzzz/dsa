/*
33. Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

#include "common.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target)
                return mid;
            
            if(nums[lo] <= nums[mid]){  // 等号处理{3,1} 或者 {1} 只有一个的情况(mid = lo = 0)，1个元素也是有序；保证了下面的nums[mid] < target成立
                if(nums[lo] <= target && target < nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }else{
                // if(nums[mid+1] <= target && target <= nums[hi]) 这样写也可以
                if(nums[mid] < target && target <= nums[hi]) // mid位置一定在最大数后面，所以mid后一定是有序（mid == lo的例外情况已被上面if处理）
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        
        return -1;
    }
};

int main(){
    Solution S;
    vector<int> nums{3,1};  //{1}
    cout << S.search(nums, 1) << endl;
}