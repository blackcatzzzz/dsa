/*
32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

#include "common.h"

// dp
class Solution_DP {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(s[i] == ')') {
                if(s[i - 1] == '('){
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }else if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '('){
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }

                ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};

// 双指针+贪心

// stack
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int ans = 0;
        stk.push(-1);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                stk.push(i);
            }else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }else{
                    ans = max(ans, i - stk.top());
                }
            }
        }

        return ans;
    }
};

int main(){

}