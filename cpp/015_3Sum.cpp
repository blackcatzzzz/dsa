/*
15. 3Sum
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include "common.h"

// https://blog.csdn.net/starflyyy/article/details/106955473
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n < 3) return ans;
        
        sort(nums.begin(), nums.end());
        if(nums[0] > 0 || nums[n - 1] < 0) return ans;

        for(int i = 0; i < n - 2;){
            if(nums[i] > 0) break;
            int first = i + 1, last = n - 1;
            do{
                int sum = nums[i] + nums[first] + nums[last];
                if(sum == 0){
                    ans.push_back(vector<int>{nums[i], nums[first], nums[last]});
                    do{
                        first++;
                    }while(first < last && nums[first] == nums[first - 1]);
                    do{
                        last--;;
                    }while(first < last && nums[last] == nums[last + 1]);
                }else if(sum < 0){
                    do{
                        first++;
                    }while(first < last && nums[first] == nums[first - 1]);
                }else if(sum > 0){
                    do{
                        last--;;
                    }while(first < last && nums[last] == nums[last + 1]);
                }
            }while(first < last);

            do{
                i++;
            }while(i < n && nums[i] == nums[i - 1]);
        }

        return ans;
    }
};

int main(){
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    Solution S;
    S.threeSum(nums);

    nums = {-1, -1, -1, 2};
    S.threeSum(nums);
}
