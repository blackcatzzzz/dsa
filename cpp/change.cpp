// Source:https://leetcode.com/problems/coin-change-2/

/*
518. Coin Change 2

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
*/

#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

// https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/bei-bao-zi-ji
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // base case
        for(int i = 0; i < n + 1; i++)
            dp[i][0] = 1;

        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < amount + 1; j++){
                if(j - coins[i -1] < 0){
                    dp[i][j] = dp[i - 1][j];
                }else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[n][amount];
    }
};

// 压缩DP为一维
class Solution1 {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);

        // base case
        dp[0] = 1;

        for(int i = 0; i < n; i++){
            for(int j = 1; j < amount + 1; j++){
                if(j - coins[i] >= 0){
                    dp[j] = dp[j] + dp[j - coins[i]];
                }
            }
        }

        return dp[amount];
    }
};

int main(){
    Solution1 s;
    vector<int> coins{1, 2, 5};
    int amount = 5;
    cout << s.change(5, coins) << endl;
}