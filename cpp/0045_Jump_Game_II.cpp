
/*
45. Jump Game II
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
*/

#include "common.h"

// https://labuladong.gitbook.io/algo/gao-pin-mian-shi-xi-lie/tiao-yue-you-xi
// 贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int end = 0, farthest = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            farthest = max(nums[i] + i, farthest);
            if(i == end){
                jumps++;
                end = farthest;
            }
        }

        return jumps;
    }
};

class Solution_DP{
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        memo = vector<int>(n, n);
        return dp(nums, 0);
    }

    int dp(vector<int>& nums, int p){
        int n = nums.size();
        // base case
        if(p >= n - 1) return 0;

        if(memo[p] != n) return memo[p];
        int steps = nums[p];
        for(int i = 1; i <= steps; i++){
            int subProblem = dp(nums, p + i);
            memo[p] = min(memo[p], subProblem + 1);
        }

        return memo[p];
    }
private:
    vector<int> memo;
};

class Solution1{
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // memo = vector<int>(n, n);
        if(!helper(nums, 0)) 
            cout << "can't reach" << endl;
        return jumps;
    }

    bool helper(vector<int>& nums, int p){
        // int n = nums.size();
        // base case
        if(p >= nums.size() - 1) return true;
        jumps++; // jump to nextPos

        int steps = nums[p];
        if(steps == 0) return false;
        int farthest = 0;
        int nextPos = p;
        for(int i = 1; i <= steps; i++){
            if(farthest <= nums[p + i]){
                farthest = nums[p + i];
                nextPos = p + i;
            }
        }

        if(helper(nums, nextPos))
            return true;

        return false;
    }
private:
    int jumps = 0;
};


int main(){
    // vector<int> nums{2,3,1,1,4};
    vector<int> nums{2,3,1,0,1,10};
    Solution S;
    cout << S.jump(nums) << endl;

    Solution_DP DP;
    cout << DP.jump(nums) << endl;

    Solution1 S1;
    cout << S1.jump(nums) << endl;
}