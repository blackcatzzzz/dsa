/*
188. Best Time to Buy and Sell Stock IV
Say you have an array for which the i-th element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

#include "common.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || k <= 0) return 0;

        if(k > n / 2)
            return maxProfit_inf(prices);

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        // base case：
        // dp[-1][k][0] = dp[i][0][0] = 0
        // dp[-1][k][1] = dp[i][0][1] = -infinity

        //base case
        for(int i = 0; i < n; i++){
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
        }

        //base case
        for(int j = 1; j <= k; j++){
            dp[0][j][0] = 0;
            dp[0][j][1] = -prices[0];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }

    int maxProfit_inf(vector<int>& prices) {
        int maxprofit = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i + 1] - prices[i] > 0)
                maxprofit += prices[i + 1] - prices[i];
        }

        return maxprofit;
    }
};

int main(){

}