/*
47. Permutations II
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used = vector<bool>(nums.size());
        backtrack(nums);
        return res;
    }
private:
    void backtrack(vector<int>& nums){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i])
                continue;

            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums);
            path.pop_back();
            used[i] = false;
        }
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> used;
};