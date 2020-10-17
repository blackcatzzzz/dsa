/*
16. 3Sum Closest
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
*/

#include "common.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        if(n < 3) return ans;
        
        sort(nums.begin(), nums.end());

        int ans_diff = INT_MAX;
        for(int i = 0; i < n - 2;){
            int first = i + 1, last = n - 1;
            do{
                int sum = nums[i] + nums[first] + nums[last];
                if(sum == target)
                    return target;

                int cur_diff = abs(sum - target);
                if(cur_diff < ans_diff){
                    ans = sum; 
                    ans_diff = cur_diff;
                }

                if(sum < target){
                    do{
                        first++;
                    }while(first < last && nums[first] == nums[first - 1]);
                }else{
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
    vector<int> nums{1,2,5,10,11};
    int target = 12;
    Solution S;
    cout << S.threeSumClosest(nums, target) << endl;
}
