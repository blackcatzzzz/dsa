// Source : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/*
167. Two Sum II - Input array is sorted

Easy

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/

#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        int sum = 0;
        while(left <= right){
            sum = numbers[left] + numbers[right];
            if(sum == target)
                return vector<int>{left + 1, right + 1};
            else if(sum < target)
                left++;
            else if(sum > target)
                right--;
        }

        return vector<int>{-1, -1};
    }
};

int main(){
    vector<int> nums{2,7,11,15};
    Solution S;
    printVector(S.twoSum(nums, 9));
}