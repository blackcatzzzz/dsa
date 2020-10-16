/*
22. Generate Parentheses
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
        if(n <= 0) return ans;
        map = {{'(', n}, {')', n}};
        string s;
        helper(n * 2, s);
        return ans;
    }

private:
    void helper(int n, string& s){
        if(map['('] > map[')'])
            return;

        if(n == s.size()){
            ans.push_back(s);
            return;
        }

        if(map['('] > 0){
            s.push_back('(');
            map['(']--;
            helper(n, s);
            s.pop_back();
            map['(']++;
        }

        if(map[')'] > 0){
            s.push_back(')');
            map[')']--;
            helper(n, s);
            s.pop_back();
            map[')']++;
        }
    }

    unordered_map<char, int> map;
    vector<string> ans;
};

int main(){
    Solution S;
    printVector(S.generateParenthesis(3));
}