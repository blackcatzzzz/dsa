/*
27. Remove Element
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,1,2,2,3,0,4,2], val = 2,

Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.

Note that the order of those five elements can be arbitrary.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

#include "common.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            while(left <= right && nums[right] == val) right--;
            while(left <= right && nums[left] != val) left++;
            if(left < right)
                swap(nums[left], nums[right]);
        }

        return right + 1;
    }
};

// i指向当前填充的位置，j指向待选择的元素，如果nums[j] != val, 则填充nums[i] = nums[j]
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; // 当前要填充的位置
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};


int main(){
    vector<int> nums{2,2,2,3};
    Solution S;
    cout << S.removeElement(nums, 2) << endl;
    printVector(nums);
}