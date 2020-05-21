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