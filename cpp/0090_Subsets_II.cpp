/*
90. Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used = vector<bool>(nums.size());
        for(int k = 1; k <= nums.size();k++)
            dfs(nums, 0, k);
        res.push_back(vector<int>());
        return res;
    }

private:
    void dfs(vector<int>& nums, int start, int k){
        if(k == path.size()){
            res.push_back(path);
            return;
        }

        for(int i = start; i <= nums.size() - (k - path.size()); i++){
            if(i >= 1 && !used[i - 1] && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, i + 1, k);
            path.pop_back();
            used[i] = false;
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;
};


int main(){
    Solution S;
    vector<int> nums = {1,2,2};
    printVectors(S.subsetsWithDup(nums));
}