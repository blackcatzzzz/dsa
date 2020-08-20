/*
46. Permutations
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
            if(find(path.begin(), path.end(), nums[i]) != path.end())
                continue;
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
        }
    }

private:
    vector<int> path;
    vector<vector<int>> res;
};

int main(){
    Solution S;
    S.permute(vector<int>{1,2,3});
}