/*
40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }

private:
    void dfs(vector<int>& candidates, int start, int target){
        // if(target < 0) return;
        if(target == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = start; i < candidates.size(); i++){
            if(target - candidates[i] < 0)
                break;

            if(i != start && candidates[i] == candidates[i - 1]) 
                continue;

            path.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};

int main(){
    Solution S;
    vector<int> nums{10,1,2,7,6,1,5};
    S.combinationSum2(nums, 8);
}