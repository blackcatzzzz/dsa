/*
169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

#include "common.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, maxCnt = 0;
        for(auto& num : nums){
            counts[num]++;
            if(counts[num] > maxCnt){
                maxCnt = counts[num];
                majority = num;
            }
        }
        return majority;
    }
};

int main(){

}