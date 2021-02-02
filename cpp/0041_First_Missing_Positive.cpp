/*
41. First Missing Positive
Given an unsorted integer array nums, find the smallest missing positive integer.

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
 

Constraints:

0 <= nums.length <= 300
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space?

*/

#include "common.h"

// O(n) , uses constant extra space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] > 0 && nums[i] < nums.size() && nums[i] - 1 != i && nums[nums[i] - 1] != nums[i]){
                swap(nums, i, nums[i] - 1);
            }
        }

        for(int i = 1; i <= nums.size(); i++){
            if(nums[i - 1] != i)
                return i;
        }

        return nums.size() + 1;
    }

private:
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};


// hash, extra space
class Solution_Hash {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto num : nums){
            set.insert(num);
        }

        for(int i = 1; i <= nums.size() ; i++){
            if(!set.count(i))
                return i;
        }

        return nums.size() + 1;
    }
};

int main(){
    Solution S;
    vector<int> nums = {1,1};
    cout << S.firstMissingPositive(nums);
}