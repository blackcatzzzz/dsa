/*
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include "common.h"

class Solution {
public:
    Solution(){
        map = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
            };
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0)  return ans;

        string s;
        helper(digits, 0, n, s);
        return ans;
    }

    void helper(string digits, int c, int n, string& s){
        if(c >= n){
            ans.push_back(s);
            return;
        }
        
        string letters = map[digits[c]];
        for(int i = 0; i < letters.size(); i++){
            s.push_back(letters[i]);
            helper(digits, c + 1, n, s);
            s.pop_back();
        }
    }

private:
    unordered_map<char, string> map;
    vector<string> ans;
};

int main(){
    string digits = "23";
    Solution S;
    printVector(S.letterCombinations(digits));
}