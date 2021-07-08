/*
140. Word Break II
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/

#include "common.h"

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for(auto word : wordDict){
          wordSet.insert(word);
        }

        int len = s.size();
        /* dp[i] = true 表示前缀子串长度i为可分割的子串 */
        vector<bool> dp(len + 1, false); 
        dp[0] = true;

        for(int i = 1; i <= len; i++){
          for(int left = i - 1; left >= 0; left--){
            string suffix = s.substr(left, i - left);
            if(wordSet.count(suffix) && dp[left]){
              dp[i] = true;
              break;
            }
          }
        }

        if(dp[len]){
            dfs(s, len, wordSet, dp);
        }
        
        return res;
    }

private:    
    vector<string> res;
    deque<string> path;

    void dfs(string &s, int len, unordered_set<string>& wordSet, vector<bool>& dp){
        if(len == 0){
            string str;
            for(int i = 0; i < path.size(); i++){
                str += path[i]; 
                if(i != path.size() - 1)
                    str += " ";
            }
            res.push_back(str);
            return;
        }

        for(int i = len - 1; i >= 0; i--){
            string suffix = s.substr(i, len - i);
            if(wordSet.count(suffix) && dp[i]){
                path.push_front(suffix);
                dfs(s, i, wordSet, dp);
                path.pop_front();
            }
        }
    }
};

int main(){
    Solution S;
    string s = "pineapplepenapple";
    vector<string> wordDict{"apple", "pen", "applepen", "pine", "pineapple"};
    printVector(S.wordBreak(s, wordDict));
}