
/*
115. Distinct Subsequences
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It's guaranteed the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

0 <= s.length, t.length <= 1000
s and t consist of English letters.
*/

#include "common.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        ans = 0;
        _t = t;
        string res;
        helper(s, 0);
        return ans;
    }

private:
    void helper(const string& s, int start){
        if(res.size() == _t.size()){
            ++ans;
            return;
        }

        if(start == s.size())
            return;

        stringstream ss;
        ss << start << "@" << res.size();
        string key(ss.str());
        if(memo.count(key)){
            ans += memo[key];
            return;
        }

        int count_pre = ans;
        for(int i = start; i < s.size(); i++){
            if(s[i] != _t[res.size()])
                continue;
            res.push_back(s[i]);
            helper(s, i + 1);
            res.pop_back();
        }

        int count_inc = ans - count_pre;
        memo[key] = count_inc;
    }


private:
    string res;
    int ans;
    string _t;
    unordered_map<string, int> memo;
};

int main(){
    Solution S;
    string s = "babgbag", t = "bag";
    cout << S.numDistinct(s, t);
}