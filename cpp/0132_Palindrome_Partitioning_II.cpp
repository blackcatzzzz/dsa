/*
132. Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lower-case English letters only.
*/

#include "common.h"

class Solution_Timeout {
public:
    int minCut(string s) {
        len = s.size();
        res = INT_MAX;
        dp = vector<vector<bool>>(len, vector<bool>(len + 1, false));
        dfs(s, 0, 0);
        return res - 1;
    }

private:
    void dfs(const string& s, int start, int count){
        if(start == len){
            res = min(count, res);
            return;
        }

        for(int i = 1; i + start <= len; i++){
            string subStr = s.substr(start, i);
            if(dp[start][i] || isPalindrome(subStr)){
                dp[start][i] = true;
                dfs(s, start + i, count + 1);
            }
        }
    }

    bool isPalindrome(const string& s){
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }
        return true;
    }

private:
    vector<vector<bool>> dp;
    int len;
    int res;
};

int main(){
    Solution S;
    string s = "ababababababababababababcbabababababababababababa";
    cout << S.minCut(s);
}