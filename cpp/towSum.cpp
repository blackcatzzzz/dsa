
/*
1. Two Sum

Easy

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i <= nums.size(); i++)
            hash[nums[i]] = i;
        
        for(int i = 0; i <= nums.size(); i++){
            int other = target - nums[i];
            if(hash.count(other))
                return vector<int>{i, hash[other]};
        }
    }
};

class Solution_Force {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() <= 0) 
            return vector<int>();
        
        for(int i = 0; i <= nums.size(); i++){
            for(int j = i + 1; j <= nums.size(); j++){
                if(nums[i] == target - nums[j])
                    return vector<int>{i, j};
            }
        }

        return vector<int>{-1, -1};
    }
};

int main(){
    Solution_Force SF;
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    printVector(SF.twoSum(nums, target));

    Solution_Force S;
    printVector(S.twoSum(nums, target));
}