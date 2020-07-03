//Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*
122. Best Time to Buy and Sell Stock II

Easy

Say you have an array prices for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


Constraints:

1 <= prices.length <= 3 * 10 ^ 4
0 <= prices[i] <= 10 ^ 4
*/

#include "common.h"

// Brute Force
class Solution_BF {
public:
    int maxProfit(vector<int>& prices) {
        return caculate(prices, 0);
    }

    int caculate(vector<int>& prices, int s){
        int max = 0;
        for(int start = s; start < prices.size(); start++){
            int maxProfit = 0;
            for(int i = start + 1; i < prices.size(); i++){
                if(prices[i] > prices[start]){
                    int profit = caculate(prices, i + 1) + prices[i] - prices[start];
                    maxProfit = std::max(maxProfit, profit);
                }
            }
            max = std::max(max, maxProfit);
        }
        return max;
    }
};

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode/
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/best-time-to-buy-and-sell-stock-ii-zhuan-hua-fa-ji/
// 贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i + 1] - prices[i] > 0)
                maxprofit += prices[i + 1] - prices[i];
        }

        return maxprofit;
    }
};

void test_BF(vector<int>& prices){
    cout << "=======test BF========" << endl;
    printVector(prices);
    Solution_BF S;
    cout << S.maxProfit(prices) << endl;
}

void test_greedy(vector<int>& prices){
    cout << "=======test test_greedy========" << endl;
    printVector(prices);
    Solution S;
    cout << S.maxProfit(prices) << endl;    
}

int main(){
    vector<int> prices{7,1,5,3,6,4};
    test_BF(prices);
    test_greedy(prices);

    prices = {1,2,3,4,5};
    test_BF(prices);
    test_greedy(prices);
}
