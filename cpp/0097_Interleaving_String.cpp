
/*
97. Interleaving String
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lower-case English letters.
*/

#include "common.h"


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return helper(s1, s2, s3);
    }

private:
    bool helper(const string& s1, const string & s2, const string& s3){
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 + len2 != s3.size())
            return false;

        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;

        for(int i = 0; i <= len1; i++){
            for(int j = 0; j <= len2; j++){
                if(i > 0)
                    dp[i][j] = s1[i - 1] == s3[i + j -1] && dp[i - 1][j];

                if(j > 0)
                    dp[i][j] = dp[i][j] || (s2[j - 1] == s3[i + j -1] && dp[i][j - 1]);
            }
        }

        return dp[len1][len2];
    }
};

int main(){

}