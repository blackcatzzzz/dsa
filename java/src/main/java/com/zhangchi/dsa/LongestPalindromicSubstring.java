package com.zhangchi.dsa;

/**
 * LeetCode 5. 最长回文子串
 * @author Chi Zhang
 * @date 2018/6/26
 */
public class LongestPalindromicSubstring {

    /**
     * 动态规划解法
     * 思路：
     * 1. 初始边界, dp[i][i] = 1, dp[i][i+1] = s[i] == s[i+1] ? 1 : 0
     * 2. 状态转移方程, dp[i][j] = s[i] == s[j] && dp[i+1][j-1] ? 1 : 0
     * 3. 安装子串起始位置与子串长度进行枚举
     * @param s
     * @return
     */
    public String longestPalindromicSubstring(String s){
        if(s.length() == 0)
            return "";

        int i = 0, j = 0, subLen = 0; // 3个控制变量
        int maxLen = 1; // 记录最大长度
        int start = 0; // 最长子串的起始位置
        int[][] dp = new int[s.length()][s.length()];

        // 初始化子串长度为1和2的dp
        for (i = 0; i < s.length(); ++i){
            dp[i][i] = 1;
            if(i < s.length() - 1 && s.charAt(i) == s.charAt(i+1)){
                dp[i][i+1] = 1;
                maxLen = 2;
                start = i;
            }
        }

        for (subLen = 3; subLen <= s.length(); ++subLen){
            for (i = 0;  (j = i + subLen - 1) < s.length(); ++i){
                if(s.charAt(i) == s.charAt(j) && dp[i+1][j-1] == 1){
                    dp[i][j] = 1;
                    maxLen = subLen;
                    start = i;
                }
            }
        }

        return s.substring(start, start + maxLen);
    }

    public static void main(String[] args){
        LongestPalindromicSubstring lps = new LongestPalindromicSubstring();
        System.out.println(lps.longestPalindromicSubstring("12321"));
    }

}
