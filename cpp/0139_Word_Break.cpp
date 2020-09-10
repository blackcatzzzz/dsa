/*
139. Word Break
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

#include "common.h"


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        len = s.size();
        vector<bool> dp(len + 1, false);
        for(auto& word : wordDict)
            wordDictSet.insert(word);

        dp[0] = true;
        for(int i = 1; i <= len; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && wordDictSet.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[len];
    }

private:
    int len = 0;
    unordered_set<string> wordDictSet;
};


// time out
class Solution_timeout {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        len = s.size();
        for(auto& word : wordDict)
            wordExist[word] = true;
        return helper(s, wordDict, 0);
    }

private:
    bool helper(const string& s, vector<string>& wordDict, int start){
        if(start == len)
            return true;

        for(int i = 1; i <= len - start; i++){
            if(!wordExist[s.substr(start, i)])
                continue;
            if(helper(s, wordDict, start + i))
                return true;
        }

        return false;
    }

private:
    int len = 0;
    unordered_map<string, bool> wordExist;
};

int main(){
    Solution S;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    cout << S.wordBreak(s, wordDict);
}