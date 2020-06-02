// Source:

/*
887. Super Egg Drop

You are given K eggs, and you have access to a building with N floors from 1 to N. 

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

 

Example 1:

Input: K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
Example 2:

Input: K = 2, N = 6
Output: 3
Example 3:

Input: K = 3, N = 14
Output: 4
 

Note:

1 <= K <= 100
1 <= N <= 10000
*/


#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/gao-lou-reng-ji-dan-wen-ti
// https://leetcode.com/problems/super-egg-drop/discuss/159079/Python-DP-from-kn2-to-knlogn-to-kn

// 穷举 动态规划 O(K*N^2)
// dp[K][N] : K个鸡蛋面对N层楼， 扔鸡蛋最少的次数
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));
        // base case
        for(int i = 1; i < K + 1; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        for(int j = 1; j < N + 1; j++)
            dp[1][j] = j;
            
        for(int i = 2; i < K + 1; i++){
            for(int j = 2; j < N + 1; j++){
                for(int k = 1; k < j + 1; k++){
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
                }
            }
        }

        return dp[K][N];
    }
};

// https://leetcode.com/problems/super-egg-drop/discuss/159055/Java-DP-solution-from-O(KN2)-to-O(KNlogN)
// 二分搜索优化 O(K*NlogN)
class Solution1 {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));
        // base case
        for(int i = 1; i < K + 1; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        for(int j = 1; j < N + 1; j++)
            dp[1][j] = j;
            
        for(int i = 2; i < K + 1; i++){
            for(int j = 2; j < N + 1; j++){
                int min = INT_MAX;
                int low = 1, hi = j;
                while(low <= hi){
                    int mid = (low + hi) / 2;
                    int a = dp[i - 1][mid - 1]; // broken
                    int b = dp[i][j - mid]; // not broken
                    dp[i][j] = std::min(dp[i][j], max(a, b) + 1);
                    // min = std::min(min, max(a, b) + 1);
                    if(a == b)
                        break;
                    else if(a < b){
                        low = mid + 1;
                    }else
                    {
                        hi = mid - 1;
                    }
                }
                // dp[i][j] = min;
            }
        }

        return dp[K][N];
    }
};

//  O(KN) dp[K][m]: K个鸡蛋 m次尝试， 测试N层楼
// TODO: dp数组还可以优化成一维
class Solution2 {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        // base case
        // dp[0][..] = 0
        // dp[..][0] = 0
        int m = 0;      
        while(dp[K][m] < N){
            m++;
            for(int k = 1; k < K + 1; k++){
                dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
            }
        }

        return m;
    }
};

int main(){
    int K = 3, N = 14;
    Solution2 s;
    cout << s.superEggDrop(K, N) << endl;
}