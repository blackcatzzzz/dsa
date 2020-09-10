/*
137. Single Number II
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/

#include "common.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seen_once = 0, seen_twice = 0;
        for(auto& num : nums){
            seen_once = ~seen_twice & (seen_once ^ num);
            seen_twice = ~seen_once & (seen_twice ^ num);
        }

        return seen_once;
    }
};

class Solution_map {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto& num : nums)
            m[num]++;

        for(auto& num : nums)
            if(m[num] == 1)
                return num;
    }
};

class Solution_set {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        int total_sum = 0, set_sum = 0;
        for(auto& num : nums){
            set.insert(num);
            total_sum += num;
        }
            

        for(auto& iter = set.begin(); iter != set.end(); iter++)
            set_sum += *iter;

        return (set_sum * 3 - total_sum) / 2;
    }
};

int main(){
    vector<int> nums = {0,1,0,1,0,1,99};
    Solution_map S;
    cout << S.singleNumber(nums);
}