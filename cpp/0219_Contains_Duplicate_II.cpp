/*
219. Contains Duplicate II
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

#include "common.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++){
            if(set.count(nums[i]))
                return true;

            set.insert(nums[i]);
            if(set.size() > k)
                set.erase(nums[i - k]);
        }

        return false;
    }
};

class Solution_BF {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j - i <= k; j++){
                if(nums[i] == nums[j])
                    return true;
            }
        }

        return false;
    }
};

int main(){
    Solution S;
    vector<int> nums = {1,2,3,1,2,3};
    cout << S.containsNearbyDuplicate(nums , 2);
}