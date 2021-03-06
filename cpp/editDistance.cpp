// Source:https://leetcode.com/problems/edit-distance/description/

/**
72. Edit Distance

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
**/

#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

// https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/bian-ji-ju-li
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m  = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // base case
        for(int i = 1; i < m + 1; i++)
            dp[i][0] = i;

        for(int j = 1; j < n + 1; j++)
            dp[0][j] = j;

        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j -1];
                }else{
                    dp[i][j] = min(dp[i][j - 1], dp[i -1][j], dp[i -1][j - 1]) + 1;
                }
            }
        }

        return dp[m][n];
    }

    int min(int a, int b, int c){
        return std::min(std::min(a, b), c);
    }
};

int main(){
    Solution s;
    string word1 = "intention", word2 = "execution";
    cout << s.minDistance(word1, word2) << endl;
}
