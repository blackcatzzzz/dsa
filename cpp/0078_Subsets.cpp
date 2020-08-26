/*
78. Subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      for(int i = 1; i <= nums.size(); i++)
        dfs(nums, 0, i);
      res.push_back(vector<int>());
      return res;
    }

private:
    void dfs(vector<int>& nums, int start, int k){
        if(path.size() == k){
            res.push_back(path);
            return;
        }

        // 剪枝
        for(int i = start; i <= nums.size() - (k - path.size()); i++){
            path.push_back(nums[i]);
            dfs(nums, i + 1, k);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};

int main(){
    Solution S;
    vector<int> nums = {1,2,3};
    printVectors(S.subsets(nums));
}