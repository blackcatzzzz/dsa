// Source : https://leetcode.com/problems/generate-parentheses/

/*
22. Generate Parentheses

Medium

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include "common.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n <= 0)
            return res;
        string track;
        helper(n, n, track, res);

        return res;
    }

    // 可用的左括号数量为 left 个，可用的右括号数量为 rgiht 个
    void helper(int left, int right, string& track, vector<string>& res){
        if(left > right) return;
        if(left < 0 || right < 0) return;
        if(left == 0 && right == 0) {
            res.push_back(track);
            return;
        }

        track.push_back('(');
        helper(left - 1, right, track, res);
        track.pop_back();

        track.push_back(')');
        helper(left, right - 1, track, res);
        track.pop_back();
    }
};

int main() {
    Solution S;
    vector<string> res = S.generateParenthesis(3);
    printVector(S.generateParenthesis(3));
}