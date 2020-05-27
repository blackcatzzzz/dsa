// Source: https://leetcode.com/problems/partition-equal-subset-sum/

/*
416. Partition Equal Subset Sum

Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums)
            sum += num;
        if(sum % 2 != 0)
            return false;

        sum = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        for(int i = 0; i < n + 1; i++)
            dp[i][0] = true;

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < sum + 1; j++){
                if(j - nums[i - 1] < 0){
                    dp[i][j] = dp[i - 1][j];
                }else{
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }
};

// dp空间压缩为一维
class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums)
            sum += num;
        if(sum % 2 != 0)
            return false;

        sum = sum / 2;
        int n = nums.size();
        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for(int i = 0; i < n; i++){
            for(int j = sum; j > 0; j--){
                if(j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[sum];
    }
};




int main(){
    vector<int> nums{1, 5, 11, 5};
    Solution1 s;
    cout << s.canPartition(nums) << endl;

    vector<int> nums1{1, 2, 3, 5};
    cout << s.canPartition(nums1) << endl;
}