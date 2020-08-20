/*
39. Combination Sum
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 

Constraints:

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
Each element of candidate is unique.
1 <= target <= 500
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }

private:
    void dfs(vector<int>& candidates, int start, int target){
        if(target == 0)
            res.push_back(path);
        
        for(int i = start; i < candidates.size(); i++){
            if(target - candidates[i] < 0)
                break;

            path.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i]);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};

int main(){
    Solution S;
    vector<int> nums{2,3,6,7};
    vector<vector<int>> res = S.combinationSum(nums, 7);
    getchar();
}