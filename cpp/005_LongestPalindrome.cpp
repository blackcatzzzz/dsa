/*
5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/


#include "common.h"

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0; i < s.size(); i++){
            string s1 = helper(s, i, i);
            string s2 = helper(s, i, i + 1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }

        return res;
    }

private:
    string helper(const string& s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--; r++;
        }

        return s.substr(l + 1, r - l - 1);
    }
};

class Solution_DP {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2)
            return s;

        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int i = 0; i < len; i++)
            dp[i][i] = true;

        int start = 0;
        int maxLen = 1;
        
        // 根据dp[i + 1][j - 1] 和 终点 dp[i][j] 来判断如何遍历
        for(int j = 1; j < len; j++){
            for(int i = 0; i < j; i ++){
                if(s[i] != s[j])
                    continue;

                if(j - i < 3) // dp[i + 1][j - 1] 有效性
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i + 1][j - 1];
                
                if(dp[i][j] && j - i + 1 > maxLen){
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

class Solution_Manacher {
public:
    string longestPalindrome(string s) {
        string newStr("$#");
        for(char c : s){
            newStr.push_back(c);
            newStr.push_back('#');
        }
        newStr.push_back('@');

        vector<int> P(newStr.size(), 0); // 回文半径，不包含中心点
        int R = 0, C = 0;
        int maxCenter = 1;
        for(int i = 1; i < newStr.size() - 1; i++){
            if(i < R){
                int iMirror = 2 * C - i;
                P[i] = min(P[iMirror], R - i); // a.左越界先转换为右贴界(R - i)；b.右贴界或正常情况则直接复制
            }

            while(newStr[i + P[i] + 1] == newStr[i - P[i] - 1])
                P[i] += 1;

            if(P[i] + i > R){
                C = i;
                R = i + P[i];
            }

            if(P[i] > P[maxCenter])
                maxCenter = i;
        }


        // string res;
        // for(int i = maxCenter - P[maxCenter]; i <= maxCenter + P[maxCenter]; i++){
        //     if(newStr[i] != '#')
        //         res.push_back(newStr[i]);
        // }
        // return res;

        // 用 P 的下标 i 减去 P [ i ]，再除以 2 ，就是原字符串的开头下标了。
        return s.substr((maxCenter - P[maxCenter]) / 2, P[maxCenter]);
    }
};



int main(){
    string s = "abba";
    Solution_DP S;
    cout << S.longestPalindrome(s) << endl;
}