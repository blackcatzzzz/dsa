/*
131. Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

#include "common.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {
        len = s.size();
        dp = vector<vector<bool>>(len,vector<bool>(len + 1, false));
        backtrack(s, 0);
        return res;
    }

private:
    void backtrack(const string& s, int start){
        if(start == len){
            res.push_back(path);
            return;
        }

        for(int i = 1; i <= len - start; i++){
            string subStr = s.substr(start, i);
            if(dp[start][i] || isPalindrome(subStr)){
                dp[start][i] = true;
                path.push_back(subStr);
                backtrack(s, start + i);
                path.pop_back();
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
    int len = 0;
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> dp;
};

int main(){
    Solution S;
    string s = "aab";
    vector<vector<string>> res = S.partition(s);
    printVectors(res);
}