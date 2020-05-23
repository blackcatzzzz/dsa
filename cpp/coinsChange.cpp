// Source : https://leetcode.com/problems/coin-change/

/*
322. Coin Change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/

#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

// https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/dong-tai-gui-hua-xiang-jie-jin-jie

// 找零钱 dp方法 自底向上
int coinsChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, amount + 1);
	// base caes
	dp[0] = 0;

	for (int i = 0; i < dp.size(); i++) {
		for (int coin : coins) {
			if (i - coin < 0)
				continue;
			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}

	return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int main() {
	vector<int> coins{1, 2, 5};
	int amount = 11;
	cout << coinsChange(coins, amount) << endl;
}