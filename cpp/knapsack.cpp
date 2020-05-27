// Source: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/bei-bao-wen-ti


// 给你一个可装载重量为 W 的背包和 N 个物品，每个物品有重量和价值两个属性。其中第 i 个物品的重量为 wt[i]，价值为 val[i]，现在让你用这个背包装物品，最多能装的价值是多少？

// 举个简单的例子，输入如下：
// N = 3, W = 4
// wt = [2, 1, 3]
// val = [4, 2, 3]
// 算法返回 6，选择前两件物品装进背包，总重量 3 小于 W，可以获得最大价值 6

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for(int i = 1; i < N + 1; i++){
        for(int w = 1; w < W + 1; w++){
            if(w - wt[i-1] < 0){
                dp[i][w] = dp[i-1][w]; // 这种情况下只能选择不装入第i个物品
            }else{
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - wt[i-1]] + val[i-1]); // 装入还是不装入，择优
            }
        }
    }

    return dp[N][W];
}

int main(){
    vector<int> wt{2, 1, 3};
    vector<int> val{4, 2, 3};
    cout << knapsack(3, 3, wt, val) << endl;
}