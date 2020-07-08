
/*
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

#include "common.h"


// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/ji-yu-zhuang-tai-ji-de-dong-tai-gui-hua-geng-jia-t/
class Solution {
public:
    // 首先，我们应明确建模对象。在这里，我们可以对某一天结束时投资者的资金状态建模。
    // 我们可以将本题中资金分为3个状态，分别用hold，cooldown和free表示。
    // 顾名思义，hold表示持有股票；cooldown表示当天刚刚卖出股票，资金处于冻结状态；
    // free表示资金自由状态，不持有股票，也不处于冻结状态。
    // 状态 free->free free->hold
    //      hold->hold hold->cooldown
    //      cooldown->free
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        // dp[i][0] = max(dp[i-1][0], dp[i-1][2]) // 不持股 free
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]) // 持股 hold
        // dp[i][2] = dp[i-1][1] + prices[i] // cooldown

        // base case 定义 第一天 好理解, （如想定义base为-1，可反推）
        int dp_free = 0, dp_hold = -prices[0], dp_cd = INT_MIN;
        for(int i = 1; i < prices.size(); i++){
            int pre_cd = dp_cd;
            // dp_cd = max(dp_hold + prices[i], dp_cd); // 不可能， 注意状态的定义是某天结束时
            dp_cd = dp_hold + prices[i];
            dp_hold = max(dp_hold, dp_free - prices[i]);
            dp_free = max(dp_free, pre_cd);
            printf("%d : %d %d %d\n",i, dp_cd, dp_hold, dp_free);
        }

        return max(dp_cd, dp_free);
    }
};

int main(){
    Solution S;
    // vector<int> prices{1,2,3,0,2};
    vector<int> prices{3,3,5,0,0,3,1,4};
    cout << S.maxProfit(prices) << endl;
}